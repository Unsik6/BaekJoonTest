// ���� 1072�� ����

// Input: 1<= X = ���ݱ��� ������ Ƚ�� <= 1000,000,000, 0<= Y = ���ݱ��� �̱� ���� <=X
// condition: �����̴� �������� ���� ����.
//			  ���� �·��� �Ҽ��� ����.


// ���� Ž�� �˰���

#include<iostream>
using namespace std;

int main()
{
	long long X, Y;
	cin >> X >> Y;
	int Z = (Y * 100) / X;
	
	if (Z >= 99)
	{
		cout << - 1;
		return 0;
	}

	int low = 0;
	int high = 1000000000;
	int target = -1;
	while (low <= high)
	{

		int mid = (high + low) / 2;
		int tmp = ((Y + mid) * 100) / (X + mid);
		if (Z >= tmp)
		{
			target = mid + 1;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << target;
	return 0;
}