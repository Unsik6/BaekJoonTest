// ���� 1258�� ���� ������

// input: ����� �� ���� ���� N (1 <= N <= 20, �ڿ���)
//		  �� ���� ������ ���� (H = �ո�, T = �޸�)

// condition: ������ ����: 1���� �� �Ǵ� ���� �ִ� ��� �������� �����´�.

// output: �ּ����� �޸鸸 ���̵��� ���� ��, �ּ����� �޸� ������ ��

// �� ���� �����⿡ ���� ���� �����Ⱑ �����ȴ�.
// �ٸ�, ������ � ���� ��� �������Ŀ� ���� ���� �����Ⱑ ���� �޶����Ƿ�,
// ��� ���� �����⸦ ���ÿ� ������ �� ����.
// ���� ��� 1��� 1���� ��� ������
// 2��� 2���� ��� �������Ŀ� ���� 1��� 1���� ������ ����� �ٶ��� �� �ִ�.
// ��� ���� ������ ��� ��쿡 ���� ���ؼ���
// ������ ���� ���� �׸��� �˰������� �ذ��� �� �ִ�.
// �� ������ Ǯ�� ���ؼ� ��Ʈ����ŷ�� �����ߴ�.

#include <iostream>
#include <math.h>
using namespace std;

int minT(int* _rowsBit, int _size, int _curRow)
{
	// ��ʹ� _curRow�� _size�� �� ������. �� ���̻� ����� ���� ����� ���� ����.
	// �� ���� ������ ���� ������ �ʴ� ��츦 ����Ѵ�.
	if (_curRow == _size)
	{
		int total = 0;
		for (int i = 0; i < _size; i++)
		{
			int not_flip_col_cnt = 0;
			for (int j = 0; j < _size; j++)
			{
				if (_rowsBit[j] & (1 << i))
				{
					not_flip_col_cnt++;
				}
			}

			total += min(not_flip_col_cnt, _size - not_flip_col_cnt);
		}

		return total;
	}

	int not_flip_row = minT(_rowsBit, _size, _curRow + 1);

	// call by pointer�̱� ������ �Ʒ�ó�� �������ָ� �����ε� ��� ������ ���·� �����ϰ� �ȴ�.
	// ������ �ᱹ ��� ����� ���� �Ǵ��� �� �ְ� �ǹǷ� ��� ����.
	_rowsBit[_curRow] = ~_rowsBit[_curRow];
	int flip_row = minT(_rowsBit, _size, _curRow + 1);

	return min(not_flip_row, flip_row);
}

int main()
{
	int N;
	cin >> N;
	
	// �� row ���� ��Ʈ����ũ�� �����.	
	int* rowsBitMask = new int[N] {0};
	for (int i = 0; i < N; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < N; j++)
		{
			if (row[j] == 'T')
			{
				// 1 << j�� j��° ��Ʈ�� 1�� �ϴ� ����,
				// i��° row�� ��Ʈ����ũ�� j��° ��Ʈ�� 1�� �ٲ��ִ� ���� �ǹ��Ѵ�.
				rowsBitMask[i] |= (1 << j);
			}
		}
	}

	cout << minT(rowsBitMask, N, 0);


	delete[] rowsBitMask;
	return 0;
}
