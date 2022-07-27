/* ���� 2252�� �� �����
*
* Input: 	�л� ��� N (1 <= N <= 32,000)
*			�� Ƚ�� M (1<= M <= 100,000)
*		 <�ι�° �� ... >
*			A B (�л� A�� �л� B �տ�) ( 1 <= A, B <= N)
*
* Output: �� �����
*
* Point: ��������
*		 ��Ʈ������ �����ϸ� �� ��.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adjList[32001];
bool isVisited[32001]{ false };
int outDegOrder[32001];

bool myComp(int a, int b)
{
	return adjList[a].size() > adjList[b].size();
}

int main()
{
	int N, M, a, b;
	cin >> N >> M;


	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adjList[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		outDegOrder[i] = i;
	}

	sort(outDegOrder + 1, outDegOrder + N + 1, myComp);

	queue<int> ret;
	stack<int> dfs;
	for (int i = 1; i <= N; i++)
	{
		if (!isVisited[outDegOrder[i]])
		{
			dfs.push(outDegOrder[i]);
			
			while (!dfs.empty())
			{
				int top = dfs.top();
				while(!adjList[top].empty())
				{
					dfs.push(adjList[top][0]);
					adjList[top].erase(adjList[top].begin());
				}

				top = dfs.top();
				if (adjList[top].empty())
				{
					ret.push(top);
					dfs.pop();
					isVisited[top] = true;
				}
			}
		}
	}

	while (!ret.empty())
	{
		if (isVisited[ret.front()])
		{
			isVisited[ret.front()] = false;
			cout << ret.front() << ' ';
		}
		ret.pop();		
	}
}