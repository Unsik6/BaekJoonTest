// ���� 1932�� �����ﰢ��

// input: 1 <= n = �ﰢ���� ũ��(����) <= 500 (�ڿ���)
//		  �� �ٸ��� ���������� �Ʒ��� �ﰢ���� �������� �־�����. (0 <= x <= 9999)

// condition: ���������� ��������, ���� ������ ������ �밢�� ���� �Ǵ� ������ �Ʒ��� �����ϸ� ������ �� �ִ�.

// matrix�� memoziation
// row�� �� ���̴�.

#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;

	int max = 0;
	int** mat = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mat[i] = new int[n];
		for (int f = 0; f <= i; f++)
		{
			cin >> mat[i][f];

			// first level don't have previous level
			if (i > 0)
			{
				// the first number of each level only from the first number of previous level
				if (f == 0)
					mat[i][f] += mat[i - 1][f];
				// the last number of each level only from the last number of previous level
				else if (f == i)
					mat[i][f] += mat[i - 1][f - 1];
				// else, the number of each level can be computed from 2 numbers of previous level
				else
				{
					int first = mat[i][f] + mat[i - 1][f - 1];
					int second = mat[i][f] + mat[i - 1][f];
					mat[i][f] = (first > second ? first : second);
				}
			}
			max = (mat[i][f] > max ? mat[i][f] : max);
		}
	}

	cout << max;
}