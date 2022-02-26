// ���� 7569�� �丶��

// input: M * N ��Ʈ���� (2 <= M, N, H <= 100)
//		  ���ڿ� ��� �丶���� ���� �Է�: 1 = ����, 0 = ���� ����, -1 = �丶�� ����
// 
// condition: ���� �丶��� ������ �丶��� �Ϸ� �Ŀ� �ʹ´�.
//			  ��ĥ�� ������ ��� �ʹ°�?

// 7576�� 3���� ����

#include<iostream>
#include<queue>
using namespace std;

int neverExplored = 1000001;
int pmR[] = {-1, 1, 0, 0, 0, 0};
int pmC[] = { 0, 0, -1, 1, 0, 0 };
int pmH[] = { 0, 0, 0, 0, -1, 1 };

int PosToInt(int _h, int _c, int _colSize, int _r, int _rowSize)
{
	return (_h * _colSize * _rowSize) + (_c * _rowSize) + _r;
}

int main()
{
	int M, N, H;
	cin >> M >> N >> H;


	queue<int> explored;
	int*** cube = new int** [H];
	int*** lvlCube = new int** [H];
	for (int h = 0; h < H; h++)
	{
		cube[h] = new int* [N];
		lvlCube[h] = new int* [N];
		for (int n = 0; n < N; n++)
		{
			cube[h][n] = new int[M];
			lvlCube[h][n] = new int[M];

			for (int m = 0; m < M; m++)
			{
				cin >> cube[h][n][m];
				if (cube[h][n][m] == -1)
					lvlCube[h][n][m] = -1;
				else if (cube[h][n][m] == 0)
					lvlCube[h][n][m] = neverExplored;
				else
				{
					lvlCube[h][n][m] = 0;
					explored.push(PosToInt(h, n, N, m, M));
				}
			}
		}
	}

	while (!explored.empty())
	{
		int cur = explored.front();
		int curRow = cur % M;
		int curCol = ((cur - curRow) / M) % N;
		int curHei = (cur - curRow - curCol * M) / (N * M);
		explored.pop();

		for (int i = 0; i < 6; i++)
		{
			if (curRow + pmR[i] >= 0 && curRow + pmR[i] < M
				&& curCol + pmC[i] >= 0 && curCol + pmC[i] < N
				&& curHei + pmH[i] >= 0 && curHei + pmH[i] < H)
			{
				if (cube[curHei + pmH[i]][curCol + pmC[i]][curRow + pmR[i]] == 0
					&& lvlCube[curHei + pmH[i]][curCol + pmC[i]][curRow + pmR[i]]
				> lvlCube[curHei][curCol][curRow] + 1)
				{
					lvlCube[curHei + pmH[i]][curCol + pmC[i]][curRow + pmR[i]] =
						lvlCube[curHei][curCol][curRow] + 1;
					explored.push(PosToInt(curHei + pmH[i], curCol + pmC[i], N, curRow + pmR[i], M));
				}
			}
		}
	}
	
	int max = 0;
	for (int h = 0; h < H; h++)
	{
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				if (lvlCube[h][n][m] == neverExplored)
				{
					max = -1;
					cout << max;
					return 0;
				}
				if (lvlCube[h][n][m] > max)
					max = lvlCube[h][n][m];
			}
		}
	}

	cout << max;


	for (int h = 0; h < H; h++)
	{
		for (int n = 0; n < N; n++)
		{
			delete[] cube[h][n];
			delete[] lvlCube[h][n];
		}
		delete[] cube[h];
		delete[] lvlCube[h];
	}
	delete[] cube;
	delete[] lvlCube;
}