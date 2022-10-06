/* ���� 8986�� ������
*
* Input: �������� �� N (1 <= N <= 100,000)
*		 �������� ��ġ�� ������������ �־�����. (xi | i=0�̸� x_i=0, �׿ܴ� 1 <= x_i <= 1,000,000,000)

* Output: ��� �̿��� ��������� �Ÿ��� ������ ��������� �̵��Ÿ� ���� �ּڰ��� ���
*
* ���Ž���� Ȱ���ϵ� �������� ã������ �ϸ� ���ѷ����� �߻��Ѵ�.
*/

#include <iostream>
using namespace std;

// input
int N;
long long poles[100000];

long long function(long long _distance)
{
	long long ret = 0;
	for (int n = 1; n < N; n++)
	{
		ret += abs(poles[n] - _distance * n);
	}
	return ret;
}

int main()
{
	cin >> N;
	for (int n = 0; n < N; n++)
		cin >> poles[n];

	long long low = 0, high = 1e9;
	while (high - low + 1 > 3)
	{
		long long p1 = (low * 2 + high) / 3;
		long long p2 = (low + high * 2) / 3;

		long long funcP1 = function(p1);
		long long funcP2 = function(p2);

		if (funcP1 < funcP2)
			high = p2;
		else
			low = p1;
	}

	long long minimum = 1e18;
	for (int i = low; i <= high; i++)
	{
		minimum = min(minimum, function(i));
	}

	cout << minimum;
}