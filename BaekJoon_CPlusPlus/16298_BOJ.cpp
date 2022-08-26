/* ���� 16298�� ��� ��ٸ� ����
*
* Input: 10x10 ������
*		 ��ٸ� �� N (1 <= N <= 15) (����: x < y, (x, y != 1, 100) : x -> y)
*		 �� �� (1 <= M <= 15)	(����: u > v : u -> v)

* Output: 1���� �����Ͽ� 100�� �����ϴ� �ּ� �ֻ��� ������ Ƚ��
*
* �ִ� ��� �����̴�. ��, �ֻ����� ������ �����ϴٴ� ���� ��ٸ��� �쿡 ���� �̹� �湮�� ������ ��湮�ؾ� �ִ� ��ΰ� ���� �� �ִ�.
* �׷��Ƿ� flag�� ������� �ʴ´�.
*/

#include <iostream>
#include <queue>

using namespace std;

int dis[101];

int ladders[101]{ 0 };		//ladders[x] = y
int snakes[101]{ 0 };		// snakes[u] = v

struct cmp
{
	bool operator()(int _a, int _b)
	{
		{
			return (dis[_a] < dis[_b]);
		}
	}
};


int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		ladders[x] = y;
	}
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		snakes[u] = v;
	}
	for (int i = 0; i < 101; i++)
		dis[i] = 10000;

	priority_queue<int, vector<int>, cmp> pq;
	pq.push(1);
	dis[1] = 0;

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();

		for (int dice = 1; dice < 7; dice++)
		{
			int dst = cur + dice;

			// 100 ������ �Ѿ�� ���̻� ������ �� ����.
			if (dst > 100) continue;

			// ��ٸ��� �쿡 ���� �������� �ٲ�� ���
			if (snakes[dst] != 0)
				dst = snakes[dst];
			else if (ladders[dst] != 0)
				dst = ladders[dst];

			if (dis[dst] > dis[cur] + 1)
			{
				dis[dst] = dis[cur] + 1;
				pq.push(dst);
			}
		}
	}

	cout << dis[100];

	return 0;
}