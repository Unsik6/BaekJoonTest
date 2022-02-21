// ���� 1912�� ������

// input: 1 <= n = ������ ����<= 100,000
//		  -1,000 <= x <= 1,000

// condition: �����ϴ� ���� �ִ� ��


// [n, n] ��Ʈ������ �̿��Ѵ�. [i, j]�� i���� j������ �κ� ������ ���̴�. (0 <= i <= j <= n-1)

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int** mat = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mat[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		//  [i, i]�̹Ƿ� a[i]�� �ִ����̴�.
		cin >> mat[i][i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int f = i - 1; f >= 0; f--)
		{
			int max = mat[i - 1][f];
			if (max < mat[i][f + 1]) max = mat[i][f + 1];
			int sum = 0;
			for (int k = f; k <= f; k++)
				sum += mat[k][k];
			if (max < sum) max = sum;

			mat[i][f] = max;
		}
	}
	cout << mat[n - 1][n - 1];
}
