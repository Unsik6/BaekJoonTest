// ���� 1697�� ���ٲ���

// input: ������ ��ġ (0 <= N <= 100,000)
//		  ������ ��ġ (0 <= K <= 100,000)
// 
// condition: ��ġ�� X�� ���, �̵� ���� ��ġ: X + 1, X - 1, X * 2

// BFS
// X��  X + 1, X - 1, X * 2�� ����Ǿ� �ִ� �����̴�.
// ����, �����̰� i��° �̵� �� ������ K �ʰ��� ����  (K - X / 2 - 1 > X - K)�̸�,
// �̶� ������ -1�� i��° �̵����� X * 2�ϴ� �̵��̴�.
// �����ϸ�, K + K/3 - 2/3 > X�̰�, K�� X ��� �����̱� ������
// int ����� ����Ͽ� K/3�� floor(K/3)�̹Ƿ�,
// K + K/3 + 2 > X �̴�.

#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int size = K + K / 3 + 2;
	int* route = new int[size + 1];
	for (int i = 0; i < size + 1; i++) route[i] = size + 1;
	// if N >= K then N can move only index 1
	if (N == K) cout << 0;
	else if (N > K) cout << N - K;
	else
	{
		queue<int> explored;
		explored.push(N);
		route[N] = 0;
		while (!explored.empty())
		{
			int cur = explored.front();
			explored.pop();
			if (cur - 1 > 0) // if cur == 0 then only way is cur++ because if cur < 0 then cur * 2 is more far position
			{
				if (route[cur - 1] > route[cur] + 1)
				{
					route[cur - 1] = route[cur] + 1;
					explored.push(cur - 1);
				}
			}
			if (cur + 1 <= size)
			{
				if (route[cur + 1] > route[cur] + 1)
				{
					route[cur + 1] = route[cur] + 1;
					explored.push(cur + 1);
				}
			}
			if (cur * 2 <= size)
			{
				if (route[cur * 2] > route[cur] + 1)
				{
					route[cur * 2] = route[cur] + 1;
					explored.push(cur * 2);
				}
			}
		}

		cout << route[K];
	}
}