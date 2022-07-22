// ���� 13398�� Ʈ���� �θ� ã��

// input: ������ ũ�� (1 <= n <= 100,000)
//		  ������ ��� (-1,000 <= x <= 1,000)
// 
// condition: �������� 1���� ������ �� �ִ�.

// �Ϲ����� ������ ������ �����ϴ�.
// �ٸ� ���հ� �������� ����ó�� �ش� ��Ҹ� �������� �� ������ �߿��ϴ�.

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* sequence = new int[n];
	for (int i = 0; i < n; i++) cin >> sequence[i];

	// no destroy element
	int* dp1 = new int[n] {0};
	// destroy element
	int* dp2 = new int[n] {0};
	dp1[0] = sequence[0];
	dp2[0] = 0;

	int max = dp1[0];

	for (int i = 1; i < n; i++)
	{
		// dp1
		if (dp1[i - 1] + sequence[i] < sequence[i])
		{
			dp1[i] = sequence[i];
		}
		else
		{
			dp1[i] = dp1[i - 1] + sequence[i];
		}


		// dp2
		if (dp1[i - 1] > dp2[i - 1] + sequence[i])
		{
			dp2[i] = dp1[i - 1];
		}
		else
		{
			dp2[i] = dp2[i - 1] + sequence[i];
		}

		if (max < dp1[i]) max = dp1[i];
		if (max < dp2[i]) max = dp2[i];
	}

	cout << max;


	delete[] sequence;
	delete[] dp1;
	delete[] dp2;
}