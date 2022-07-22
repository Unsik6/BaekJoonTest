// ���� 4673�� �����ѹ�

// condition: d(n) = n + (n�� �� �ڸ� ��)
//			  n�� d(n)�� �����ڶ�� �� ��, �����ڰ� ���� ���� ���� �ѹ���� �Ѵ�.
//			  10000���� ���� ���� ���� �� ���� �ѹ����� �����Ͽ� ����ϴ� �Լ��� �ۼ��Ͻÿ�.

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int d(int _n)
{
	int result = _n;
	while (true)
	{
		result += _n % 10;
		_n = int(_n / 10);
		if (_n == 0) break;
	}
	return result;
}

int main()
{
	bool arr[10001]{ true };
	for (int i = 1; i < 10000; i++)
	{
		int index = d(i);
		if (index <= 10000) arr[index] = true;
	}

	for (int i = 1; i < 10000; i++)
		if (!arr[i]) cout << i << endl;
	return 0;
}