// ���� 11399�� ATM

// input: 1 <= N = ����� �� <= 1,000
//		  1 <= �� ����� �� �̴µ� �ɸ��� �ð� Pi <= 1,000

// condition: i��° ���� ���ִ� ����� �� �̴µ� �ɸ��� �ð� Sk = sum(Pk | 1 <= k <= Pk)
//			  ������� ���� ���� �� sum(Sk | 1 <= k <= n)�� �ּҰ��� ���Ͽ���

// i�� ���� ���� �� ���� �������Ƿ� �տ� �� ���� ���� ���ڿ��� �Ѵ�.

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int sum = 0;
	int minTotal = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
		minTotal += sum;
	}

	cout << minTotal;
}