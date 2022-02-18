// ���� 11053�� ���� �� �����ϴ� �κ� ����

// input: 1 <= N = ������ ũ�� <= 1,000 (�ڿ���)
//		  ������ 1 <= Ai <= 1,000 (����)

// condition:  ���� �� �����ϴ� �κм���

// ���̰� ª�� �ͺ��� �����Ͽ�, ������ �κм������� ���̿� ������ ���� ���� ���� ���� �����Ѵ�.

#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arr = new int[N + 1];
	int* memo = new int[N + 1];
	arr[0] = memo[0] = 0;
	int max = 0;
	for (int i = 1; i < N + 1; i++)
	{
		cin >> arr[i];
		memo[i] = 0;
		for (int f = i - 1; f > 0; f--)
		{
			if (arr[i] > arr[f] && memo[i] < memo[f])
			{
				memo[i] = memo[f];
			}
		}
		memo[i]++;
		if (max < memo[i]) max = memo[i];
	}
	cout << max;
}