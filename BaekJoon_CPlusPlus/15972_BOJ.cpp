/* ���� 15972 ����ũ
*
* Input: ����ũ�� ���α��� N, ���� ���� M, ���� H (1 <= N, M, H <= 1,000)
*		 ù��° ���κ��� ��ġ�� ���� ������ ��Ÿ���� M���� ����
*			������� �� ĭ�� ���� ���� h (0 <= h < H, ���� ������ -1)
*		 ���κ� i�� �����ϴ� ĭ���� ���κ� ������� ������ ���̵�

* Output: ���� �� �̻� �귯������ �ʴ� �������� �����ִ� ���� ��
*/
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0);
#define MAX 1'004	// ���� �ٱ��� �׵θ��� ����ũ ���ε� ��ǲ ���� �� ���������� �� ĭ �� �߰�
#define pii pair<int, int>

// input
int N, M, H;
void input();


// partition info
// partitions[row][col][1,2,3,4 = �����¿�]
int partitions[MAX][MAX][4];
int heights[MAX][MAX]{ 0 };

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// ��ǥ �̵�
int dRow[4] = { -1, 1, 0, 0 };
int dCol[4] = { 0, 0, -1, 1 };
int RC_to_Offset(int _r, int _c) { return _r * MAX + _c; }
pii Offset_to_RC(int _os) { return {_os / MAX, _os % MAX}; }

// Solution - ���ͽ�Ʈ��
priority_queue<pii, vector<pii>, greater<pii>> PQ_Part;	// {height, Offset}
void solution();

// Debugging
void check();

int main()
{
	FAST_IO
	input();
	solution();
	return 0;
}

void input()
{
	cin >> N >> M >> H;
	
	// ���κ� (����̶�� �����ϰ� �Է� ����)
	for (int n = 1; n <= N + 1; n++)
	{
		for (int m = 1; m <= M; m++)
		{
			cin >> partitions[n][m][UP];
			partitions[n - 1][m][DOWN] = partitions[n][m][UP];
		}
	}

	// ���κ� (�����̶�� �����ϰ� �Է� ����)
	for (int n = 1; n <= N; n++)
	{
		for (int m = 1; m <= M + 1; m++)
		{
			cin >> partitions[n][m][LEFT];
			partitions[n][m - 1][RIGHT] = partitions[n][m][LEFT];
		}
	}

	// �� ä���
	for (int n = 1; n <= N; n++)
	{
		for (int m = 1; m <= M; m++)
			heights[n][m] = H;
	}
}

void solution()
{
	// preprocessing 1. �����ڸ� ĭ�� ���� �����ϸ鼭 PQ�� ����
	// 1) ���� ĭ Ȯ��
	for (int m = 1; m <= M; m++)
	{
		// ������ ���� ������ ����
		if (partitions[1][m][UP] != -1)
		{
			if (heights[1][m] > partitions[1][m][UP])
			{
				heights[1][m] = partitions[1][m][UP];
				PQ_Part.push({ heights[1][m], RC_to_Offset(1, m) });
			}
		}
			
		// �Ʒ����� �Ʒ��� ������ ����
		if (partitions[N][m][DOWN] != -1)
		{
			if (heights[N][m] > partitions[N][m][DOWN])
			{
				heights[N][m] = partitions[N][m][DOWN];
				PQ_Part.push({ heights[N][m], RC_to_Offset(N, m) });
			}
		}
	}
	// 2) �¿� ĭ Ȯ��
	for (int n = 1; n <= N; n++)
	{
		// �������� ���� ������ ����
		if (partitions[n][1][LEFT] != -1)
		{
			if (heights[n][1] > partitions[n][1][LEFT])
			{
				heights[n][1] = partitions[n][1][LEFT];
				PQ_Part.push({ heights[n][1], RC_to_Offset(n, 1) });
			}
		}
		if (partitions[n][M][RIGHT] != -1)
		{
			if (heights[n][M] > partitions[n][M][RIGHT])
			{
				heights[n][M] = partitions[n][M][RIGHT];
				PQ_Part.push({ heights[n][M], RC_to_Offset(n, M) });
			}
		}
	}

	while (!PQ_Part.empty())
	{
		pii curRC = Offset_to_RC(PQ_Part.top().second);
		int curHeight = PQ_Part.top().first;
		PQ_Part.pop();

		// �湮Ȯ��
		if (heights[curRC.first][curRC.second] != curHeight)
			continue;

		for (int i = 0; i < 4; i++)
		{
			if (partitions[curRC.first][curRC.second][i] == -1)
				continue;
			int nextR = curRC.first + dRow[i];
			int nextC = curRC.second + dCol[i];
			
			if (nextR < 1 || nextR > N || nextC < 1 || nextC > M)
				continue;
			int next_height = max(heights[curRC.first][curRC.second], 
				min(partitions[curRC.first][curRC.second][i], heights[nextR][nextC]));
			if (heights[nextR][nextC] > next_height)
			{
				heights[nextR][nextC] = next_height;
				PQ_Part.push({ next_height, RC_to_Offset(nextR, nextC) });
			}
		}
	}

	// ��ġ��
	int sum = 0;
	for (int n = 1; n <= N; n++)
		for (int m = 1; m <= M; m++)
			sum += heights[n][m];

	cout << sum;
}

void check()
{
	cout << "\nCHECK\n";
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= M; c++)
		{
			cout << "[" << r << "][" << c << "] : {";
			for (int i = 0; i < 4; i++)
			{
				cout << partitions[r][c][i] << ", ";
			}
			cout << "} H = ";
			cout << heights[r][c];
			cout << '\n';
		}
	}
}