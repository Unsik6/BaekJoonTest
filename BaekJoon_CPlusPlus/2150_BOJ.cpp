/* ���� 2150 Strongly Connected Component
*
*Input: ������ �� V, ������ �� E (1 <= V <= 10,000 ,1 <= E <= 100,000)
*		���� ��ȣ A, B ( A -> B, 1 <= A, B <= V )

* Output: �� ��Ģ 2���� �����ϸ鼭 �ο� ��ü�� �ɴ� ��� ����� ������ ���Ͻÿ�.
*/

// ������ ������ �ִ�10,000���̹Ƿ� |V|^2�� 100,000,000(�� 95 MB)�̴�.
// E�� ��쿡 ���� O(|V|^2)������ �޸𸮿� ������ �����Ƿ� Adjacency Matrix�� �̿��ص� �ȴ�.
// ������ �ð� �ʰ��� �߻��� ���� �ִ�. Adjacency Matrix������ DFS�� �����µ� O(|V|^2)�� �ʿ��ϴ�.
// �ϳ��� �������� ����� �ٸ� ������ ã�� ���� O(|V|)�� �ð����⵵�� �ʿ��ϱ� �����̴�.
// O(|V|^2) / 100,000,000 = �� 1���̹Ƿ� �ι��� DFS�� �����ϴ� ���忡�� �ð��� �� Ÿ��Ʈ�ϴ�.
// �׷��� �� Adjcency List�� �̿��ϱ�� �ߴ�. �ٸ�,SCC�� �����Ͽ� ã�� ���� �׳� O(|V|^2)�� �ߴ�.

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// input
int V, E;

// graph
vector<int> graph[10001];
vector<int> graphT[10001];

// dfs info
bool visited[10001]{ false };

// scc
stack<int> endDFS;
int sccCnt = 0;
int sccLeader[10002]{ 0 };

void firstDFS(int _vIdx)
{
	visited[_vIdx] = true;

	for (int i = 0; i < graph[_vIdx].size(); i++)
	{
		int adjV = graph[_vIdx][i];

		if (!visited[adjV])
		{
			firstDFS(adjV);
		}
	}

	endDFS.push(_vIdx);
}

void reset()
{
	for (int i = 1; i <= V; i++)
		visited[i] = false;
}

void secondDFS(int _vIdx, int _sccL)
{
	visited[_vIdx] = true;
	sccLeader[_vIdx] = _sccL;

	for (int i = 0; i < graphT[_vIdx].size(); i++)
	{
		int adjV = graphT[_vIdx][i];

		if (!visited[adjV])
		{
			secondDFS(adjV, _sccL);
		}
	}
}

int main()
{
	cin >> V >> E;

	for (int e = 0; e < E; e++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graphT[b].push_back(a);
	}

	// first DFS
	for (int i = 1; i <= V; i++)
	{
		if(!visited[i])
			firstDFS(i);
	}

	// reset visited arr
	reset();

	// second DFS
	while (!endDFS.empty())
	{
		int curV = endDFS.top();
		endDFS.pop();
		if (!visited[curV])
		{
			secondDFS(curV, curV);
			sccCnt++;
		}
	}

	// output
	cout << sccCnt << '\n';
	
	for (int i = 1; i <= V; i++)
	{
		if (sccLeader[i] > 0)
		{
			cout << i << ' ';
			for (int j = i + 1; j <= V; j++)
			{
				if (sccLeader[i] == sccLeader[j])
				{
					cout << j << ' ';
					sccLeader[j] = 0;
				}
			}
			
			cout << -1 << '\n';
		}
	}

	return 0;
}