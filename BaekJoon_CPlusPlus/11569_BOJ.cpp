/* ���� 11569�� ��ȣ��
*
* Input: �׽�Ʈ ���̽� ���� T (1 <= T <= 10)
*		 ������(����)�� �� N (1 <= N <= 100,000)
*		 ������(����)�� �� M (1 <= M <= 100,000)
*		 ��� �������� ��ȣ S (1 <= S <= N)
*		 ���� �������� ��ȣ D (1 <= D <= N)
* 
*		 M���� �� src: a, dst: b, wht: c (1<= a, b <= N, a != b, 1 <= c <= 100,000)
*		 �� �������� ��ȣ�� �ֱ� P_i (1 <= i <= N, 1 <= P_i <= 100)
*		 �� ������ ���̿��� �ִ� �Ѱ��� ���θ� �����Ѵ�.
*
* Output: ù° ��: �ּ� �ð� ��� (64 bit ������ �� ��) - ��ΰ� ���� ��� -1
* 
* 
*		 1) �ڵ����� 1�ʿ� 1�� ���̸�ŭ �̵��Ѵ�
*		 2) ��� ��ȣ���� �ڵ����� ��߰� ���ÿ� �����Ѵ�.
*		 3) ��� �����ο� ������ �����ο����� ��ȣ�� ��ٸ� �ʿ䰡 ����.
*		 4) � �����ο��� ���� �����η� ���ƿ��� ��(self-loop)�� ����.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// input
int T, N, M, src, dst;
long long ret;
long long distances[100001];
long long periods[100001];
vector<pair<int, int>> adjacencyLists[100001]; // pair.frst = dst, second = weight


struct vertexInfo
{
	int id;
	long long d;
	int par;

	// std::priority_queue�� ����ϱ� ���� �ݴ�� ��ȯ�ϰ� �Ѵ�.
	bool operator < (const vertexInfo& _a)
	{
		return (this->d > _a.d);
	}
};

struct compVI
{
	bool operator ()(vertexInfo a, vertexInfo b)
	{
		return a.d > b.d;
	}
};

bool pairComp(pair<int, int> a, pair<int, int> b)
{
	if (a.first < b.first) return true;
	else return false;
}

int main()
{
	
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		// input
		cin >> N >> M >> src >> dst;
		for (int m = 0; m < M; m++)
		{
			int s;
			pair<int, int> dw;
			cin >> s >> dw.first >> dw.second;
			adjacencyLists[s].push_back(dw);
			adjacencyLists[dw.first].push_back(pair<int, int>{s, dw.second});
		}
		for (int i = 1; i <= N; i++)
		{
			cin >> periods[i];
		}
			

		for (int i = 1; i <= N; i++)
		{
			sort(adjacencyLists[i].begin(), adjacencyLists[i].end(), pairComp);
			distances[i] = -1;
		}

		// initialize return value
		ret = -1;

		priority_queue<vertexInfo, vector<vertexInfo>, compVI> fringes;	// frist is vertex id, second is distance.
		vertexInfo tmp{ src, 0, -1 };
		fringes.push(tmp);
		while (!fringes.empty())
		{
			vertexInfo newTree = fringes.top();
			fringes.pop();
			
			// break ��Ȳ 1) ������ ����, 2) ���� ����
			if (newTree.id == dst)
			{
				ret = newTree.d;
				break;
			}
			if (adjacencyLists[newTree.id].empty())
			{
				break;
			}

			long long delayTime = 0;
			if (newTree.par != -1)	// �������� ��� ����
			{
				// ���� newTree�� ��𼭺��� ���� �ڵ����� �����Ű�°�
				long long whatOn = (newTree.d / periods[newTree.id]) % (long long)adjacencyLists[newTree.id].size();
				// �ش� ������ ���۵��� �󸶳� �Ǿ���
				long long onTime = (newTree.d % periods[newTree.id]);
				// newTree�� ���� ���� ��� �Դ���, �׸��� �� ������ newTree���忡�� ���°����
				long long seq = 0;

				for (int k = 0; k < adjacencyLists[newTree.id].size(); k++)
				{
					if (adjacencyLists[newTree.id][k].first == newTree.par)
					{
						seq = k;
						break;
					}
				}

				// ��ٷ��� �Ǹ� delayTime ���
				if (whatOn != seq)
				{
					if (whatOn > seq) seq += (long long)adjacencyLists[newTree.id].size();
					delayTime = (seq - whatOn - 1) * periods[newTree.id] + (periods[newTree.id] - onTime);
				}
			}

			for (int i = 0; i < adjacencyLists[newTree.id].size(); i++)
			{
				int destIdx = adjacencyLists[newTree.id][i].first;

				// �ش� ���� ���ؽ��� ���� �ð��� ���ݱ��� �Ҹ��� �ð� + ��ٸ� �ð� + ���θ� �������� �ð�
				long long newDistance = newTree.d + delayTime + (long long)adjacencyLists[newTree.id][i].second;

				if (distances[destIdx] == -1 || distances[destIdx] > newDistance)
				{
					distances[destIdx] = newDistance;
					vertexInfo newVI{ destIdx, newDistance, newTree.id };
					fringes.push(newVI);
				}
			}
		}

		cout << ret << '\n';

		for (int i = 1; i <= N; i++)
		{
			if (!adjacencyLists[i].empty()) adjacencyLists[i].clear();
		}
	}
}