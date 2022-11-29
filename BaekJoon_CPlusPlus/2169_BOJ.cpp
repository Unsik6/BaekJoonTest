/* ���� 2169 �κ� �����ϱ�
*
* Input: 2���� �迭�� ũ�� N, M ( 1<= N, M <= 1,000)
*		 N �ٿ� M���� ��ġ k (|k| <= 100)
* 
*		 ����, ������, �Ʒ������� �̵��� �� �ִ�. (������ �Ұ���)
*		 �ѹ� Ž���� ������ Ž������ �ʴ´�.

* Output: [1,1]���� ����ϰ� [N, M]�� �������� �� Ž���� �������� ��ġ ���� �ִ�
*/

#include <iostream>

using namespace std;

#define MAX_SIZE 1000
#define MAX 0
#define RIGHT 1

int N, M;
int arr2_ori[MAX_SIZE][MAX_SIZE];
int arr3_max[MAX_SIZE][MAX_SIZE][2]{0};

int main()
{
	// �Է�
	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> arr2_ori[r][c];
		}
	}

	// ù ��: ���ʿ��� ���� �͸� ����
	arr3_max[0][0][MAX] = arr2_ori[0][0];
	for (int c = 1; c < M; c++)
	{
		arr3_max[0][c][MAX] = arr3_max[0][c - 1][MAX] + arr2_ori[0][c];
	}
	// �߰� ��
	for (int r = 1; r < N - 1; r++)
	{
		// ���ʺ��� �����ϴ� ���
		// ���� ���� ���ʿ� �ִ� ���� �������� �� �� �����Ƿ� �ʱ�ȭ ����
		arr3_max[r][0][MAX] = arr3_max[r - 1][0][MAX] + arr2_ori[r][0];

		// �� �������ʹ� ������ �� ���� ���ʿ��� �� ����� MAX�� DP�� ���
		for (int c = 1; c < M; c++)
		{
			// ���ʿ��� �� ��찡 �� ū ���
			if (arr3_max[r][c - 1][MAX] > arr3_max[r - 1][c][MAX])
				arr3_max[r][c][MAX] = arr3_max[r][c - 1][MAX];
			// ������ �� ��찡 �� ū ���
			else
				arr3_max[r][c][MAX] = arr3_max[r - 1][c][MAX];

			arr3_max[r][c][MAX] += arr2_ori[r][c];
		}

		// �����ʺ��� �����ϴ� ���
		// ���ʰ� ���������� ���� �����ʿ� �ִ� �� ���� �ʱ�ȭ
		// ���ʿ��� ���� �Ŷ� ����� ���� ��ġ�� �� �ǹǷ� ���� ����
		arr3_max[r][M - 1][RIGHT] = arr3_max[r - 1][M - 1][MAX] + arr2_ori[r][M - 1];

		// ���ʿ��� ���� �Ͱ� ����
		for (int c = M - 2; c >= 0; c--)
		{
			// �����ʿ��� �� ��찡 �� ū ���
			if (arr3_max[r][c + 1][RIGHT] > arr3_max[r - 1][c][MAX])
				arr3_max[r][c][RIGHT] = arr3_max[r][c + 1][RIGHT];
			// ������ �� ��찡 �� ū ���
			else
				arr3_max[r][c][RIGHT] = arr3_max[r - 1][c][MAX];

			arr3_max[r][c][RIGHT] += arr2_ori[r][c];;
		}

		// �ִ밪 ��
		for (int c = 0; c < M; c++)
		{
			if (arr3_max[r][c][RIGHT] > arr3_max[r][c][MAX])
				arr3_max[r][c][MAX] = arr3_max[r][c][RIGHT];
		}
	}
	
	// ������ �� ó��
	// ���� 1���� �׳� ����ϸ� �ȴ�.
	if (N < 2)
	{
		cout << arr3_max[N - 1][M - 1][MAX];
	}
	else
	{
		// ���� ���� ���ʿ� �ִ� ���� �������� �� �� �����Ƿ� �ʱ�ȭ ����
		arr3_max[N - 1][0][MAX] = arr3_max[N - 2][0][MAX] + arr2_ori[N - 1][0];

		for (int c = 1; c < M; c++)
		{
			// ���ʿ����� �� �� �ִ�.
			// ���ʿ��� �� ��찡 �� ū ���
			if (arr3_max[N - 1][c - 1][MAX] > arr3_max[N - 2][c][MAX])
				arr3_max[N - 1][c][MAX] = arr3_max[N - 1][c - 1][MAX];
			// ������ �� ��찡 �� ū ���
			else
				arr3_max[N - 1][c][MAX] = arr3_max[N - 2][c][MAX];

			arr3_max[N - 1][c][MAX] += arr2_ori[N - 1][c];
		}

		cout << arr3_max[N - 1][M - 1][MAX];
	}

	
	return 0;
}