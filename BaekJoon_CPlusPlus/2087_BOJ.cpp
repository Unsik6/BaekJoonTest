/* ���� 2087 ��ȣ��
*
*Input: bit�� �� n (5<= n <= 40)
*		n���� �ٿ� �ڿ��� a_i (sum(a_1, a_2, ... a_n) <= 2'000'000'000)
*		K

* Output : K = a_1 * t_1 + a_2 * t_2 + ... + a_n * t_n�� �����ϴ� ���� ��ȣ�� t_1t_2t_3...t_n (t_i = 0 OR 1)
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define POW2_20 1048576

// input
int N, K, halfSize;
int As1[20], As2[20];

// Sum table
// 2'000'000'000�� 2^20���� ���� ũ�� ������ case ���� �����Ѵ�.
// �����ؼ� ����Ž������ �˻��ؾ� �ϱ� ������ case�� ���� �����Ѵ�.
pair<int, int> halfSum1[POW2_20];	// half[case] = {��, case}
pair<int, int> halfSum2[POW2_20];

int computeHalf(int* _arrAs, pair<int, int>* _sumArr, int _halfSize)
{
	// ��ΰ� 0�� ���� ���� �� �ʿ� ����.
	for (int bit = 1; bit < (1 << _halfSize); bit++)
	{
		// �� ������ ��츸 ã���� �ǹǷ� �̹� ���� ���� ���� ��찡 ������ ���� ���Ѵ�.
		if (_sumArr[bit].second != 0)
			continue;

		int curCase = bit;
		int arrIdx = 0;
		int sum = 0;
		while (curCase > 0)
		{
			if (curCase % 2 == 1)
				sum += _arrAs[arrIdx];
			curCase /= 2;
			arrIdx++;
		}

		// K�� �̹� ã�� ��� bit ����
		if (sum == K)
			return bit;

		_sumArr[bit] = { sum, bit };
	}

	return -1;
}

void printDecimalToCode(int _decimal, int _size)
{
	int cnt = 0;
	while (_decimal > 0)
	{
		cout << _decimal % 2;
		_decimal /= 2;
		cnt++;
	}

	for (int i = 0; i < _size - cnt; i++)
		cout << 0;
}

bool Comp_lower_bound(const pair<int, int> _a, const pair<int, int> _b)
{
	return _a.first < _b.first;
}

int main()
{
	cin >> N;
	halfSize = N / 2;
	for (int n = 0; n < halfSize; n++)
		cin >> As1[n];
	for (int n = 0; n < N - halfSize; n++)
		cin >> As2[n];
	cin >> K;

	int checkEnd = computeHalf(As1, halfSum1, halfSize);
	// ���� �̹� K�� ã�� ���
	if (checkEnd != -1)
	{
		printDecimalToCode(checkEnd, halfSize);
		
		for (int i = 0; i < N - halfSize; i++)
			cout << 0;
		return 0;
	}
	checkEnd = computeHalf(As2, halfSum2, N - halfSize);
	if (checkEnd != -1)
	{
		// �޺κ��̴ϱ� �պκ� ���� ���
		for (int i = 0; i < N - halfSize; i++)
			cout << 0;

		printDecimalToCode(checkEnd, N - halfSize);
		
		return 0;
	}
	
	// �޺κ� �� �迭 ����
	int  size2 = 1 << (N - halfSize);
	sort(halfSum2, halfSum2 + size2);

	// �� ã��
	int firstBit = -1, secondBit = -1;
	for (int i = 1; i < (1 << halfSize); i++)
	{
		// �� �κ��� ���� 0�� ���� ������ ���� ó����.
		if (halfSum1[i].second == 0)
			continue;
		
		int targetSum = K - halfSum1[i].first;	// ���� ���� ã�ƾ� �Ѵ�.

		// ���� ���� �ƴ� ��, lower_bound ����ϴ� ���
		int targetIdx = lower_bound(halfSum2, halfSum2 + size2, pair<int,int>(targetSum, 0), Comp_lower_bound) - halfSum2;

		if (targetIdx < size2)
		{
			if (halfSum2[targetIdx].first == targetSum)
			{
				firstBit = i; secondBit = halfSum2[targetIdx].second;
				break;
			}
		}
	}

	// �� ���
	printDecimalToCode(firstBit, halfSize);
	printDecimalToCode(secondBit, N - halfSize);	

	return 0;
}