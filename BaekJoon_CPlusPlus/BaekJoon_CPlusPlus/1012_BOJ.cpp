// ���� 1012�� ����� ����

// Input: T = �׽�Ʈ ���̽��� ����, M = ���߹� ���� ����, N = ���߹� ���� ����, K = ���� ��ġ ����
//			  (1 <= N, M <= 50) (1 <= K <= 2500)
//			  (X, Y) = ���� ��ǥ (0 <= x, y < M, N)
// condition: ���ߴ� ��ĭ�� �� ����
//			  ���߰� �����¿�� �پ� ������ ����


// DFS �˰���
// ȥ�ڼ� ���� ���� ����Լ��� ����.
// ���߿� �˰��� ����� ������ �� ����

#include<iostream>
using namespace std;

void Change(bool**, int, int, int, int);

int main()
{
	int T, M, N, K;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		cin >> M >> N >> K;
		bool** field = new bool*[N];
		for (int n = 0; n < N; n++)
		{
			field[n] = new bool[M];
			for (int m = 0; m < M; m++)
				field[n][m] = 0;
		}
		
		int x, y;
		for(int k = 0; k < K; k++)
		{
			cin >> x >> y;
			field[y][x] = 1;
		}

		int regionCnt = 0;
		x = 0, y = 0;
		while (true)
		{
			if (field[y][x] == 1)
			{
				Change(field, M, N, x, y);
				regionCnt++;
			}
			if (x == M - 1)
			{
				if (y == N - 1) break;
				else
				{
					x = 0;
					y++;
				}
			}
			else x++;
		}

		cout << regionCnt << "\n";
	}
}

void Change(bool** _f, int _m, int _n, int _x, int _y)
{
	if (_f[_y][_x] == 0) return;
	
	_f[_y][_x] = 0;
	if (_y - 1 >= 0)
		Change(_f, _m, _n, _x, _y - 1);
	if (_y + 1 < _n)
		Change(_f, _m, _n, _x, _y + 1);
	if (_x - 1 >= 0)
		Change(_f, _m, _n, _x - 1, _y);
	if (_x + 1 < _m)
		Change(_f, _m, _n, _x + 1, _y);
}