// ���� 1436�� ��ȭ������

// input: 1 <= N = ����(�ڿ���) <= 10,000

// condition: 6�� 3�� �̻� �������� ���� ��

// ���Ʈ���� �˰���: ������ �Ǵ�, ���ǹ��� ���̽����� ��� �˻��ϴ� ���̴�.

#include<iostream>
using namespace std;

int main()
{
	int N, cnt{ 0 }, number{ 665 };
	cin >> N;
	
	while (cnt < N)
	{
		number++;
		int tmp = number;
		bool isSequence = false;
		int sequenceCnt = 0;
		while (tmp != 0)
		{
			int digit = tmp % 10;

			// is digit 6?
			if (digit == 6) isSequence = true;
			else isSequence = false;
			if (isSequence) sequenceCnt++;
			else sequenceCnt = 0;

			if (sequenceCnt == 3)
			{
				cnt++;
				break;
			}

			tmp /= 10;
		}
	}

	cout << number;
}