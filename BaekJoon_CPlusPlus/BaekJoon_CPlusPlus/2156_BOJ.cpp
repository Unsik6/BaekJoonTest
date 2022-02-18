// ���� 2156�� ������ �ý�

// input: 1 <= n = ������ �� �� <= 10,000 (�ڿ���)
//		   �������� �� 0 <= x <= 1,000 (����)

// condition: 1) �����ָ� �����ϸ� �� �ܿ� ����ִ� ��� ���� ���ž� �ϰ� ���� �Ŀ��� ���� ��ġ�� ���ƾ� �Ѵ�.
//			  2) �������� �����ִ� 3���� ���� �� ����.

// 2579�� ����
// case 1) �̹� �����ָ� �Դ� ���
//			OXO : DP[i-2] + A[i]
//			XXO : DP[i-3] + A[i]
//			XOO : DP[i-3] + A[i-1] + A[i]
//			�̹Ƿ� �ι�°�� ����°���� ������ ������ ��꿡�� �����Ѵ�.
// case 2) �̹� �����ָ� �� �Դ� ���
//			���ǿ� ����� ���� �����Ƿ� DP[i - 1] ��°�� ����.
// �� �� �ִ��� ��츦 ���Ѵ�.

#include <iostream>
using namespace std;

int maxInt(int _a, int _b)
{
	return (_a > _b ? _a : _b);
}

int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		int one;
		cin >> one;
		cout << one;
	}
	else if (n == 2)
	{
		int one, two;
		cin >> one >> two;
		cout << one + two;
	}
	else if (n > 2)
	{
		int* arr = new int[n + 1];
		int* memoziation = new int[n + 1];
		memoziation[0] = arr[0] = 0;
		
		cin >> arr[1];
		cin >> arr[2];
		memoziation[1] = arr[1];
		memoziation[2] = arr[1] + arr[2];
		for (int i = 3; i < n + 1; i++)
		{
			cin >> arr[i];
			int max = 0;
			// drink arr[i]
			max = maxInt(memoziation[i - 2] + arr[i], memoziation[i - 3] + arr[i - 1] + arr[i]);
			// don't drink
			max = maxInt(max, memoziation[i - 1]);

			memoziation[i] = max;
		}
		cout << memoziation[n];

		delete[] arr;
	}
}