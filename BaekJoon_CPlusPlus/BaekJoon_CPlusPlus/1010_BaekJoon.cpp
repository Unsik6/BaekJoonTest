// ���� 1010�� �ٸ� ����

// Input: T = �׽�Ʈ ���̽��� ����, N = ���� ����Ʈ ����, M = ������ ����Ʈ ����
// condition: N�� ��ŭ�� �ٸ�
//			  �ٸ������� ������ �� ����.
//			  (����) 0 < N <= M < 30 

// ����(combination)
// �ٸ��� ��� �����ϵ� �ٸ��� �����ϴ� ������ ������ �����Ƿ�
// M���� �ڽ��� N���� ������ �ִ� 1�� ���� �� �ִ� �ܿ��� ���� ����.
// C(m, n) = m! / n! (m-n)!

#include <iostream>

int main()
{
	int t;
	std::cin >> t;
	double *N = new double[t];
	double* M = new double[t];
	for(int i= 0; i < t; i++) std::cin >> N[i] >> M[i];

	for (int i = 0; i < t; i++)					// test count
	{
		// 30 �������� ���� ���� ��û ������. => �ڷ��� ����
		double limit = (N[i] > M[i] - N[i] ? M[i] - N[i] : N[i]);	// �� �������� �ݺ����� ������ ����.
		unsigned long long MFactorial = 1;
		unsigned long long limFactoial = 1;

		for (double f = 0; f < limit; f++)
		{
			MFactorial *= (M[i] - f);
			limFactoial *= (limit - f);
		}

		std::cout << MFactorial/limFactoial << "\n";
	}

	return 0;
}