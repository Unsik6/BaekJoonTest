// ���� 1978�� �Ҽ� ã��

// Input: 1<= N = �Է¹��� ������ ���� <= 100, N���� 1000 ������ ���� ����

// �Ҽ��� 1�� �ڱ� �ڽŸ����� 
// (N/2 +1)���� ��������.

#include<iostream>
using namespace std;

int main()
{
	int T, cnt{ 0 };
	bool IsPrime = true;
	cin >> T;
	int* nums = new int[T];
	for (int i = 0; i < T; i++) cin >> nums[i];
	for (int t = 0; t < T; t++)
	{
		if (nums[t] == 1) IsPrime = false;
		for (int i = 2; i < (nums[t] / 2) + 1; i++)
		{
			if (!(nums[t] % i))
			{
				IsPrime = false;
				break;
			}
		}
		if (IsPrime) cnt++;
		else IsPrime = true;
	}
	cout << cnt << endl;
}