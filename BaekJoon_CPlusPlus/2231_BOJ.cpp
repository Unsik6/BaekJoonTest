// ���� 2231�� ������

// input: 1 <= N <= 1,000,000

// condition: ������ = [N + N�� �� �ڸ����� ��] �̶�, ������ = N

// ���Ʈ���� �˰���: ������ �Ǵ�, ���ǹ��� ���̽����� ��� �˻��ϴ� ���̴�.

#include<iostream>
using namespace std;

int sum(int n)
{
	int sum = n;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int N, result{ 0 };
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		if (N == sum(i))
		{
			result = i;
			break;
		}
	}
	cout << result << endl;
}