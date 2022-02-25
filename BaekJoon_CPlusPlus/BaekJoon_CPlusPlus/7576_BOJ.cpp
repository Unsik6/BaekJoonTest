// ���� 7576�� �丶��

// input: M * N ��Ʈ���� (2 <= M, N <= 1,000)
//		  ���ڿ� ��� �丶���� ���� �Է�: 1 = ����, 0 = ���� ����, -1 = �丶�� ����
// 
// condition: ���� �丶��� ������ �丶��� �Ϸ� �Ŀ� �ʹ´�.
//			  ��ĥ�� ������ ��� �ʹ°�?

// ���̵�� ����
// ó���� �Է¹��� ���� �丶����� ��� BFS�� �������̶�� �����Ѵ�.
// ��� ���� �丶��鿡 ���ؼ� BFS�� �����ϰ�, lvl�� �ο��Ѵ�.
// �̶� ó���� �Է¹��� ���� �丶��鿡 ���� ������ �ٸ� �� �����Ƿ� ���� ���� ������ �ο��Ѵ�.
// ������ �ο��ϸ鼭 ������ �ִ밪�� ã�´�.
// BFS�� O(N * M)�̱� ������ �� ������ O((N * M)^2)�̸� �ʴ� 1����� ������ �Ѵٰ� �ϸ� 10000�ʰ� �Ҹ�ȴ�.
// 
// �̸� ���̷��� ù��° ���� BFS���� ������ �ɸ� �ȴ�.
// ù��°���� �Ϲ����� BFS�� �����Ѵ�.
// �ι�°���ʹ� BFS�� ������ ��, � ������ ������ �������� ���ų� ���ٸ�,
// �� ������ �������δ� �� �������� �ʾƵ� �ȴ�.
// �ֳ��ϸ� �ش� �������� �� ���� ������ ������ ������ �������� ���� �����̴�.
// �׷��� �ᱹ Ž���� ��ġ�� �丶�䰡 �ް��ϰ� �پ���, ��ġ�� ��찡 ���� ���� �־��� ��쿡�� O(N*M /2)�̹Ƿ�
// O(N*M)�ð��� ������ �� �ִ�.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int NeverExplored = 10000001;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> firstRipen;
	int** mat = new int* [M];
	for (int i = 0; i < M; i++)
	{
		mat[i] = new int[N] {-1};
		for (int f = 0; f < N; f++)
		{
			cin >> mat[i][f];
			if (mat[i][f] == 1)
				firstRipen.push_back(i * N + f);
		}
	}

	int** lvlMat = new int* [M];
	for (int i = 0; i < M; i++)
	{
		lvlMat[i] = new int[N];
		for (int f = 0; f < N; f++)
		{
			if (mat[i][f] == 1) lvlMat[i][f] = 0;
			else if (mat[i][f] == -1) lvlMat[i][f] = -1;
			else lvlMat[i][f] = NeverExplored;
		}
	}

	// start BFS to all firstRipen
	for (int start : firstRipen)
	{
		queue<int> explored;
		explored.push(start);
		int nextLvl = 1;
		int curLvlElemsCnt = 1;
		int nextLvlElemCnt = 0;
		while (!explored.empty())
		{
			int curVertex = explored.front();
			int curCol = curVertex % N;
			int curRow = (curVertex - curCol) / N;
			explored.pop();
			curLvlElemsCnt--;

			if (curRow > 0)
			{
				if (mat[curRow - 1][curCol] == 0
					&& lvlMat[curRow - 1][curCol] > nextLvl)
				{
					lvlMat[curRow - 1][curCol] = nextLvl;
					explored.push((curRow - 1) * N + curCol);
					nextLvlElemCnt++;
				}
			}
			if (curRow < M - 1)
			{
				if (mat[curRow + 1][curCol] == 0
					&& lvlMat[curRow + 1][curCol] > nextLvl)
				{
					lvlMat[curRow + 1][curCol] = nextLvl;
					explored.push((curRow + 1) * N + curCol);
					nextLvlElemCnt++;
				}
			}
			if (curCol > 0)
			{
				if (mat[curRow][curCol - 1] == 0
					&& lvlMat[curRow][curCol - 1] > nextLvl)
				{
					lvlMat[curRow][curCol - 1] = nextLvl;
					explored.push(curRow * N + (curCol - 1));
					nextLvlElemCnt++;
				}
			}
			if (curCol < N -1)
			{
				if (mat[curRow][curCol + 1] == 0
					&& lvlMat[curRow][curCol + 1] > nextLvl)
				{
					lvlMat[curRow][curCol + 1] = nextLvl;
					explored.push(curRow * N + (curCol + 1));
					nextLvlElemCnt++;
				}
			}

			if (curLvlElemsCnt == 0)
			{
				nextLvl++;
				curLvlElemsCnt = nextLvlElemCnt;
				nextLvlElemCnt = 0;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < M; i++)
	{
		for (int f = 0; f < N; f++)
		{
			if (lvlMat[i][f] == NeverExplored)
			{
				max = -1;
				break;
			}
			else if (max < lvlMat[i][f]) max = lvlMat[i][f];
		}
	}
		

	cout << max;




	for (int i = 0; i < M; i++)
	{
		delete[] mat[i];
		delete[] lvlMat[i];
	}
	delete[] mat;
	delete[] lvlMat;
}