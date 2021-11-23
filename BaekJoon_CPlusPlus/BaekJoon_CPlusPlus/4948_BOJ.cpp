// ���� 1948�� ����Ʈ�� ����

// input: 1 <= N <= 123,456

// condition: ����Ʈ�� ������ ������ �ڿ��� n�� ���Ͽ�,
//			  n���� ũ��, 2n���� �۰ų� ���� �Ҽ��� ��� �ϳ� �����Ѵٴ� ������ ��� �ִ�.


// �����佺�׳׽��� ä ������(1929)�� Ǯ�̸� ���� Ǯ���.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int input;
	vector<int> v_n;
	cin >> input;
	while (input != 0)
	{
		v_n.push_back(input);
		cin >> input;
	}

	for (int& n : v_n)
	{
		int size = 2 * n + 1;
		bool* numbers = new bool[size]{ false };
		int cnt = 0;
		// �����佺�׳׽� ä�� �迭�� �ʱ�ȭ
		for (int i = 2; i < size; i++)
			numbers[i] = true;
		// n�� ������ 123456�� ������ int�� ������ �Ѿ��.
		for (long long i = 2; i < size; i++)
		{
			if (i * i > size)
				break;
			if (numbers[i])
				for (long long f = i * i; f < size; f += i)
					if (!(f % i)) numbers[f] = false;
		}
		for (int i = n + 1; i < size; i++)
			if (numbers[i]) cnt++;
		cout << cnt << '\n';
	}
}