// ���� 1912�� ������

// input: 1 <= n = ������ ����<= 100,000
//		  -1,000 <= x <= 1,000

// condition: �����ϴ� ���� �ִ� ��

// dp[i]�� a[i]�� �ǳ����� �ϴ� ���ӵ� �κм����� ���̴�.
// dp[i-1] + a[i]������,
// dp[i-1] + a[i] < a[i]��� ���� ������ �ʿ䰡 �����Ƿ�, a[i]�� �ȴ�.
// �� ���, dp[i-1]�� a[i]�� ������ �������� �ִ��̹Ƿ�
// a[i]�� �����ϴ� a[i]���� ���� ������ ���� �ִ븦 �����Ѵ�.
// a[i]�� �߰��� �����ϰų�, ù��°�� �����ϴ� �κм����� ���� dp[j] (i <= j)�̴�.

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int* dp = new int[n];
	dp[0] = arr[0];
	int totalMax = dp[0];
	for (int i = 1; i < n; i++)
	{
		int max = dp[i - 1] + arr[i];
		if (max < arr[i]) max = arr[i];

		dp[i] = max;
		if (totalMax < dp[i]) totalMax = dp[i];
	}

	cout << totalMax;
}
