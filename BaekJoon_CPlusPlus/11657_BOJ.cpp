/* ���� 11657�� Ÿ�Ӹӽ�
*
* Input: <ù��° ��>
			������ ���� N (1 <= N <= 500)
*			���� �뼱�� ���� M (1<= M <= 6,000)
*		 <�ι�° �� ... >
*			�� �ٿ� ���� �뼱�� ���� A, B, C (1 <= A, B <= N, -10,000 <= C <= 10,000)
*
* Output: 1�� ���ÿ��� ����Ͽ�,
		  ���� ������ ���ŷ� ���� ��찡 �ִٸ� -1�� ���
*		  �ƴ� ���, �� ���ÿ� ���µ� �ɸ��� �ð��� �ٷ� �����Ͽ� ��� (��� ������ -1)
* 
* Point:
*		����ġ�� ������ ġ���� ���, �� ���� ����Ŭ�� �߻��� ��� ���� �ʿ��� �����÷ο찡 �߻��� �� ������ long�� ����Ѵ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 999999999

vector<pair<int, int>> adjacentLists[501];
long distances[501];

int main()
{
	int n, m, src, dst, wht;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> src >> dst >> wht;
		adjacentLists[src].push_back(make_pair(dst, wht));
	}

	// �ʱ�ȭ
	for (int i = 2; i <= n; i++)
		distances[i] = INF;
	distances[1] = 0;


	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < adjacentLists[j].size(); k++)
			{
				if (distances[j] == INF) continue;
				else
				{
					long newD = distances[j] + adjacentLists[j][k].second;
					if (newD < distances[adjacentLists[j][k].first])
					{
						distances[adjacentLists[j][k].first] = newD;
					}
				}
			}
		}
	}

	for (int j = 1; j <= n; j++)
	{
		for (int k = 0; k < adjacentLists[j].size(); k++)
		{
			if (distances[j] == INF) continue;
			else
			{
				long newD = distances[j] + adjacentLists[j][k].second;
				if (newD < distances[adjacentLists[j][k].first])
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (distances[i] == INF) cout << -1 << '\n';
		else cout << distances[i] << '\n';
	}
	
	return 0;
}