// ���� 12865�� ����� �賶

// input: 1 <= N = ��ǰ ���� <= 100
//		  1 <= K = �ִ빫�� <= 100,000
//		  �� ������ 1 <= W(����) <= 100,000
//					0 <= V(��ġ) <= 1,000

// condition: ��ġ ���� �ִ밪

// dp[i][j] = i��° ���Ǳ��� Ȯ���ϸ�, ������ ���԰� j�� ����� ��ġ���� �ִ밪
// ��� 1( j < obj[i] ): ������ ���ʿ� ���� ���� ����.
// ��� 2( j >= obj[i]): ������ ���� �� �ִ�.
//						���2-1: ������ �� �ִ´�. dp[i - 1][j]
//						���2-2: ������ �ִ´�.
//								 i-1��° ���Ǳ����� j - weight[i]��ŭ�� ���Ը� ������ְ�, ����(i��°)�� �ִ´�.
//								 dp[i - 1][j - weight[i]] + value[i]


#include<iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int* objsWeight = new int[N + 1];
	int* objValue = new int[N + 1];

	for (int i = 1; i < N + 1; i++)
		cin >> objsWeight[i] >> objValue[i];

	int** dp = new int*[N + 1];
	for (int i = 0; i < N + 1; i++)
		dp[i] = new int[K + 1];

	for (int i = 0; i < K + 1; i++) dp[0][i] = 0;
	for (int i = 0; i < N + 1; i++) dp[i][0] = 0;

	for (int i = 1; i < N + 1; i++)
	{
		for (int f = 1; f < K + 1; f++)
		{
			if (f >= objsWeight[i])
			{
				dp[i][f] = dp[i - 1][f];
				if (dp[i][f] <= dp[i - 1][f - objsWeight[i]] + objValue[i])
					dp[i][f] = dp[i - 1][f - objsWeight[i]] + objValue[i];
			}
			else dp[i][f] = dp[i - 1][f];
		}
	}

	cout << dp[N ][K];

	for (int i = 0; i < N + 1; i++)
		delete[] dp[i];
	delete[] dp;
}