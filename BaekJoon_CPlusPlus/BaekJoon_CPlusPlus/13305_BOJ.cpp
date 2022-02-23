// ���� 13305�� ������

// input: 2 <= N = ������ ���� <= 100,000
//		  City[i]�� City[i+1]�� �����ϴ� N-1���� ������ ���� D[i]
//		  1 <= sum(D[i] | 0 <= i < N-1) <= 1,000,000,000
//		  1 <= City[i]�� ���ʹ� ���� <= 1,000,000,000

// condition: ���� ���� ���� ���鼭 ������ ���� ���

// �߿��� ���� City[i]���� ������ ���� �����̴�.
// City[i].pricePerL > City[i].pricePerL �̶�� ���� ���ñ����� �� ��ŭ �����ϴ� ���� �δ�.
// else �� ������ ���� �������� City[i]���� �����ϴ� ���� �δ�.


#include <iostream>
using namespace std;

int main()
{
	long long N;
	cin >> N;

	// ������ ������ ���ʹ� ������ �ʿ������ �Է��� �޾ƾ� �ϹǷ� N���� unsigned long long�� �غ��Ѵ�.
	long long* prices = new long long[N];
	long long* distances = new long long[N - 1];

	for (int i = 0; i < N - 1; i++) cin >> distances[i];
	for (int i = 0; i < N; i++) cin >> prices[i];

	long long totalPrice = 0;
	long long curCity = 0;
	
	for (int i = 1; i < N; i++)
	{
		if (prices[i] < prices[curCity])
		{
			totalPrice += (prices[curCity] * distances[i - 1]);
			curCity = i;
		}
		else totalPrice += (prices[curCity] * distances[i - 1]);
	}

	cout << totalPrice;
}