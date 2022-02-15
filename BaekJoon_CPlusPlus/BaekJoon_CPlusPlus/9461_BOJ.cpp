// ���� 1904�� Ÿ��01

// input: 1 <= N <= 100

// condition: �ĵ��� ������ N��° ��

// ���� ���̰� 1�� ���ﰢ������ �����Ͽ� ������ �̷絵�� �ﰢ������ �̾���̵�
// ���� �� ���� �ﰢ���� �̾���δ�.
// 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28 ...
// n >= 6�� ��, P(n) = P(n-1) + P(n-5) �̴�.

#include <iostream>
using namespace std;

int main()
{
	
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		// memorization array
		long long* arr = new long long[N];
		if (N > 0) arr[0] = 1;
		if (N > 1) arr[1] = 1;
		if (N > 2) arr[2] = 1;
		if (N > 3) arr[3] = 2;
		if (N > 4) arr[4] = 2;
		for (int i = 5; i < N; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 5];
		}

		cout << arr[N - 1] << '\n';
	}
}