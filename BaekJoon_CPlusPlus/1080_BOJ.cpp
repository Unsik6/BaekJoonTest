// ���� 1026�� ����

// input: ����� ũ�� N, M (1 <= N, M <= 50)
//		  ��� A, ��� B

// condition: ����� ��ȯ-3x3�κ������ ��Ҹ� ��� �����´�. (0->1, 1->0)
//			  �ּ����� ����� ��ȯ���� A�� B�� ������. ��, �ٲ� �� ���� ��� -1 ���

// ���� �ϳ��� �������� ��ȯ�� ����Ѵ�. ���� ��� ���Ұ� B�� ���ٸ� ���̻� ��ȯ���� �ʴ´�.
// ���� �ϳ��� �ذ��� �Ŀ��� �� ���Ҵ� ��ȯ ����� �ƴϹǷ� ������ ��ȯ�� ������ ��ġ�� �ʴ´�.
// �׸��� �˰��� ���
// 
// 1. A[i, j]�� ���Ͽ� 0 <= i <= N-1, 0 <= j <= M-1���� B[i, j]�� ���� �� �˻��Ѵ�.
// 2. ���� A[i, j]�� B[i, j]�� �ٸ��ٸ� ��ȯ�Ѵ�.

#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	bool** matA = new bool* [N];
	bool** matB = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		matA[i] = new bool[M];
		string inputRow;
		cin >> inputRow;
		for (int f = 0; f < M; f++)
			matA[i][f] = inputRow[f] - '0';
	}

	for (int i = 0; i < N; i++)
	{
		matB[i] = new bool[M];
		string inputRow;
		cin >> inputRow;
		for (int f = 0; f < M; f++)
		{
			matB[i][f] = inputRow[f] - '0';
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int f = 0; f < M; f++)
		{
			if (matA[i][f] != matB[i][f] && i + 2 < N && f + 2 < M)
			{
				cnt++;
				for (int k = 0; k < 3; k++)
				{
					for (int j = 0; j < 3; j++)
					{
						matA[i + k][f + j] = !matA[i + k][f + j];
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int f = 0; f < M; f++)
		{
			if(matA[i][f] != matB[i][f])
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << cnt;


	for (int i = 0; i < N; i++)
	{
		delete[] matA[i];
		delete[] matB[i];
	}
	delete[] matA;
	delete[] matB;
}
