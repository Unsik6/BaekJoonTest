// ���� 1024�� ������ ��

// Input: N = ��, L = ����
// condition: ���� �ƴ� ���� ����Ʈ
//			  (�ڿ���) N <= 1,000,000,000 && 100 >= (�ڿ���)L >= 2


// ���� ������ ��
// An = A1 + (n-1)d
// Sn = n(2A1+(n-1)d)/2

#include <iostream>

int main()
{
	double N, L;
	std::cin >> N >> L;
	int first{ 0 };
	while (true)
	{
		// L�� 100�� �ѱ�� -1 ���
		if (L > 100)
		{
			std::cout << -1;
			return 0;
		}
		// Sn ������ ����
		// Sn = N, n = L, d = 1
		// A1 = N / L - L / 2 + 1/2
		
		double dtmpResult = (N / L) - (L / 2) + 0.5;
		if (dtmpResult < 0 || dtmpResult > 1000000000) // ù° �� ����
		{
			std::cout << -1;
			return 0;
		}

		int itmpResult = static_cast<int>(dtmpResult);
		if (dtmpResult - itmpResult != 0)
		{
			L++;
			continue;
		}
		
		first = itmpResult;
		break;
	}

	for (int i = 0; i < L; i++) std::cout << first + i << " ";

	return 0;
}