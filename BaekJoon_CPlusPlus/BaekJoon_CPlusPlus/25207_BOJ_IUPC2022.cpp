/* ���� 25207�� �ٺ�ž�� ���� // IUPC #3
*
* Input: ù° ��: ����� �� N (1 <= N <= 500,000)
*		 ��° ��: a1~aN������ N���� ���� (-10^9 <= ai <= 10^9)
*		 N-1���� ��: �� ���� i, j (i�� ��尡 j�� ����� �θ�)
*
* Output: ù° ��: ���� ����� ��
*		  ��° ��: ���� ������ ��� ��ȣ�� ���� ������ �������� �����Ͽ� ���
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info { int pIdx; int nodeNum; };

vector<int> result;

int* elemArr;
vector<int>* children;

vector<info>* dfsArr;
vector<info>* dfsrArr;

info DFS(int _root)
{
	if (children[_root].empty())
	{
		result.push_back(_root);
	}
	else
	{
		int pdelta = 1;
		for (int i = 0; i < children[_root].size(); i++)
		{
			info childInfo = (DFS(children[_root][i]));
			for (int j = 0; j < dfsArr[children[_root][i]].size(); j++)
			{
				dfsArr[_root].push_back(dfsArr[children[_root][i]][j]);
				dfsArr[_root][dfsArr[_root].size() - 1].pIdx += pdelta;
			}
			pdelta++;
			dfsArr[_root].push_back(childInfo);
		}
	}
	info tmp{ 0, _root };
	return tmp;	
}

info rDFS(int _root)
{
	int pdelta = 1;
	for (int i = children[_root].size() - 1; i >= 0; i--)
	{
		info childInfo = (rDFS(children[_root][i]));
		for (int j = 0; j < dfsrArr[children[_root][i]].size(); j++)
		{
			dfsrArr[_root].push_back(dfsrArr[children[_root][i]][j]);
			dfsrArr[_root][dfsrArr[_root].size() - 1].pIdx += pdelta;
		}
		pdelta++;
		dfsrArr[_root].push_back(childInfo);
	}
	info tmp{ 0, _root };
	return tmp;
}

int main()
{
	int N;
	cin >> N;

	elemArr = new int[N + 1];
	children = new vector<int>[N + 1];
	dfsArr = new vector<info>[N + 1];
	dfsrArr = new vector<info>[N + 1];

	for (int i = 1; i <= N; i++)
	{
		cin >> elemArr[i];
	}

	for (int i = 1; i <= N - 1; i++)
	{
		int p, c;
		cin >> p >> c;
		children[p].push_back(c);
	}

	for (int i = 1; i <= N; i++)
	{
		if (children[i].empty()) continue;
		sort(children[i].begin(), children[i].end());
	}

	DFS(1);
	rDFS(1);
	
	for (int i = 1; i <= N; i++)
	{
		if (dfsArr[i].empty())
			continue;
		else
		{
			bool isCursed = true;
			for (int j = 0; j < dfsArr[i].size(); j++)
			{
				if (elemArr[dfsArr[i][j].nodeNum] != elemArr[dfsrArr[i][j].nodeNum]
					|| dfsArr[i][j].pIdx != dfsrArr[i][j].pIdx)
				{
					isCursed = false;
					break;
				}
			}
			if (isCursed)
			{
				result.push_back(i);
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';

	return 0;
}