// ���� 2775�� �γ�ȸ���� ���׾�

// Input: T = �׽�Ʈ ���̽�, 1 <= k, n <= 14 (k�� nȣ)
// condition: a�� bȣ�� �����Ϸ��� (a-1)���� 1ȣ���� bȣ������ ����� �� ��ŭ ����� ��ƾ��Ѵ�.
//			  ����ִ� ���� ����.
//			  ����Ʈ�� 0������ ������ 1ȣ���� �ִ�. 0�� iȣ���� i��ŭ ���.

// �ܼ���, nȣ �̻��� �Ű澲�� �ʾƵ� �ȴ�.

#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int* ks = new int[T];
	int* ns = new int[T];
	for (int i = 0; i < T; i++)
		cin >> ks[i] >> ns[i];
	for (int i = 0; i < T; i++)
	{
		int* prefloor = new int[ns[i]]{ 0 };
		int* targetfloor = new int[ns[i]]{ 0 };
		for (int k = 0; k < ns[i]; k++) prefloor[k] = k + 1;
		for (int f = 1; f <= ks[i]; f++)
		{
			for (int j = 0; j < ns[i]; j++)
				for (int p = ns[i] - 1; p >= j; p--)
					targetfloor[p] += prefloor[j];
			for (int j = 0; j < ns[i]; j++)
			{
				prefloor[j] = targetfloor[j];
				targetfloor[j] = 0;
			}
		}
		cout << prefloor[ns[i] - 1] << endl;
	}
}
