// ���� 2798�� ����

// input: 3 <= N <= 100 : ī���� ��, 10 <= M <= 300,000 : ��ǥ ����
//						  ī���

// condition: 3���� ī�带 �̾� ���� �� �ִ� (<= M) �߿� ���� ū ���� ȣ���Ѵ�.
//			  �� ��찡 ������ ������ ī��鸸 �־�����.

// ���Ʈ���� �˰���: ������ �Ǵ�, ���ǹ��� ���̽����� ��� �˻��ϴ� ���̴�.

#include<iostream>
using namespace std;

int main()
{
	int N, M, result{ 0 }, max{ 0 };
	cin >> N >> M;
	int* deck = new int[N];
	for (int i = 0; i < N; i++) cin >> deck[i];
	for (int i = 0; i < N; i++)
	{
		for (int f = i + 1; f < N; f++)
		{
			for (int k = f + 1	; k < N; k++)
			{
				if (deck[i] + deck[f] + deck[k] <= M)
				{
					result = deck[i] + deck[f] + deck[k];
					max = (result > max ? result : max);
				}
			}
				
		}


	}
	cout << max;
}