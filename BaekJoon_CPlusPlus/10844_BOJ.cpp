// ���� 10844�� ���� ��ܼ�

// input: 1 <= N = ������ ���� <= 100

// condition: �� �ڸ��� ���Ͽ� ���ڸ��� ���� 1���̰� ���� ���, ��ܼ���� ��.
//			  N�� �־����� ��, ������ ��ܼ��� ��

// N���� �ڸ��� ���Ͽ� ���� �ڸ����� � ���ڰ� �����Ŀ� ���� �̹� �ڸ��� ������ ������ ���̽��� �ٸ���.

#include<iostream>
using namespace std;

int main()
{
	int arr[10] = { 0 };
	int preArr[10] = { 0 };
	long long N;
	cin >> N;
	if (N == 1) cout << 9;
	else
	{
		for (int i = 1; i < 10; i++) preArr[i] = 1;
		while (N > 1)
		{
			arr[0] = preArr[1];
			for (int i = 1; i < 9; i++)
			{
				arr[i] = (preArr[i - 1] + preArr[i + 1]) % 1000000000;
			}
			arr[9] = preArr[8];

			for (int i = 0; i < 10; i++) preArr[i] = arr[i];
			N--;
		}

		for (int i = 1; i < 10; i++)
		{
			arr[0] += arr[i];
			arr[0] %= 1000000000;
		}
		cout << arr[0] % 1000000000;
	}
}