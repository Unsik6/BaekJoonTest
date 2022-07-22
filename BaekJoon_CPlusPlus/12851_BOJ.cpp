/* ���� 12851�� ���ٲ���2
*
* Input: ������ ��ġ (0 <= N <= 100,000)
*		 ������ ��ġ (0 <= K <= 100,000)
*
* Output: �����̴� X-1�Ǵ� X+1, X*2�� �̵�
*		  ù° ��: �����̰� ������ ã�� ���� ���� �ð� ���
*		  ��° ��: ���� ���� �ð����� �����̰� ������ ã�� ����� ��
*/

#include <iostream>
#include <queue>
using namespace std;

int arr[100001]{ 0 };

int main()
{
	for (int i = 0; i < 100001; i++)
	{
		arr[i] = 1000002;
	}
	int src, dst;
	cin >> src >> dst;

	if (src == dst)
	{
		cout << 0 << '\n' << 1;
	}
	else
	{
		queue<int> visitedNodes;
		visitedNodes.push(src);
		arr[src] = 0;
		int shortestPath = 100002;
		int cnt = 0;
		while (!visitedNodes.empty())
		{
			int curNode = visitedNodes.front();
			visitedNodes.pop();

			if (curNode > 0)
			{
				if (arr[curNode - 1] >= arr[curNode] + 1)
				{
					visitedNodes.push(curNode - 1);
					arr[curNode - 1] = arr[curNode] + 1;
				}
				if (curNode - 1 == dst)
				{
					if (shortestPath == arr[curNode] + 1)
					{
						cnt++;
					}
					else if (shortestPath > arr[curNode] + 1)
					{
						shortestPath = arr[curNode] + 1;
						cnt = 1;
					}
				}
			}
			if (curNode < 100000)
			{
				if (arr[curNode + 1] >= arr[curNode] + 1)
				{
					visitedNodes.push(curNode + 1);
					arr[curNode + 1] = arr[curNode] + 1;
				}
				if (curNode + 1 == dst)
				{
					if (shortestPath == arr[curNode] + 1)
					{
						cnt++;
					}
					else if (shortestPath > arr[curNode] + 1)
					{
						shortestPath = arr[curNode] + 1;
						cnt = 1;
					}
				}
			}
			if (curNode <= 50000)
			{
				if (arr[curNode * 2] >= arr[curNode] + 1)
				{
					visitedNodes.push(curNode * 2);
					arr[curNode * 2] = arr[curNode] + 1;
				}
				if (curNode * 2 == dst)
				{
					if (shortestPath == arr[curNode] + 1)
					{
						cnt++;
					}
					else if (shortestPath > arr[curNode] + 1)
					{
						shortestPath = arr[curNode] + 1;
						cnt = 1;
					}
				}
			}
		}

		cout << shortestPath << '\n' << cnt;
	}
	
	return 0;
}