// ���� 1929�� �Ҽ� ���ϱ�

// input: 1 <= M <= N <= 1,000,000 (M�� N�� ���� ����)

// condition: N���� M������ �Ҽ����� ���� ������ ����Ѵ�.

// �����佺�׳׽��� ä�� Ǯ���
// �����佺�׳׽��� ä�� ��Ģ�� ������ ����.
// 2 <= i <= sqrt(n) + 1
// �� �������� ��� �Ҽ� i�� ���Ͽ�
// i�� ����� ������ ��� ����� �Ҽ��� ���´�.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	vector<int> prime = { 2 };		// �Ҽ��� ������ ���� �迭
	bool divided = false;

	for (int i = 1; i <= N; i++)
	{
		if (i == 1)continue; // 1�� ������ ����ó��
		if (i == 2)	// 2�� ������ ����ó��
		{
			if(M <= 2) cout << i << '\n';
			continue;
		}
		for (int& it : prime)
		{
			if (!(i % it))
			{
				divided = true;
				break;
			}
		}
		if (!divided)
		{
			prime.push_back(i);	// �Ҽ��� �� �������� �Ҽ��� �߰�
			if(i >= M)	cout << i << '\n';
		}
		divided = false;	// �Ǵ� ���� �ʱ�ȭ
	}
}