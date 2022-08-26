/* ���� 3056�� 007
*
* Input: �̼ǰ� ������ �� N (1 <= N <= 20)
*		 i��° �ٿ� j��° ���� = ���̺��� i�� �̼� j�� ������ Ȯ��

* Output: ��� �̼��� ���� ���忡�� 1���� �������� �� ��ü �̼� ���� Ȯ���� �ִ밡 �Ǵ� ���
*		  (���� ���� +-0.000001)
*
* Point:
*	N�� �����Ƿ� BF�� Ǭ��. �̶� ��Ʈ����ŷ�� �̿��Ѵ�.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, cnt, tmp;
double percent[20][20];				// ��� �� ���� Ȯ��
double bitmask[1 << 20] = { 1, };	// ��Ʈ ����ũ

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> percent[i][j];

	// ��� ����
	cout.precision(6);
	cout << fixed;

	// �� �˻� ȸ���� ��Ʈ ����ũ�� ����� ����ŭ ����
	for (int i = 0; i < (1 << N); i++)
	{
		cnt = 0;
		tmp = i;

		// ���� ��Ʈ �� ���� (��Ʈ �� = ����� ����� �����ߴ���)
		while (tmp > 0)
		{
			// ��Ʈ�� 1�� ���
			if (tmp % 2 == 1) cnt++;
			tmp /= 2;
		}

		// � �̼��� ������ ���ΰ�
		for (int j = 0; j < N; j++)
		{
			if ((i & (1 << j)) == 0)
			{
				// �� �̼��� �ϴ� ���,
				// ���Ӱ� �����ϴ� �̼��� ���� �����ϴ°� �ִ����� ���
				bitmask[i | (1 << j)] = max(bitmask[i | (1 << j)], bitmask[i] * percent[j][cnt] / 100.0);
			}
		}
	}

	// ��Ʈ����ũ�� �� á�� �� = ��� �̼��� ����Ǿ��� ���� Ȯ��
	cout << bitmask[(1 << N) - 1] * 100 << endl;
}
