// ���� 1193�� �м�ã��

// Input: 1 <= X = ��ǥ�м� <= 10,000,000
// condition: ������ �м����� ���� ����� ������׷� ����

// Ȧ�� �м��� ���ڰ� ����, �и� ���� <= �ش� ��
// ¦�� �м��� ���ڰ� ����, �и� ���� <= �ش� ��


#include<iostream>
using namespace std;

int main()
{
	int X, n{ 1 }, mom{ 0 }, son{ 0 };
	cin >> X;
	while (X - n > 0)
	{
		X -= n;
		n++;
	}
	mom = (n % 2 == 0 ? n - X + 1 : X);
	son = (n % 2 != 0 ? n - X + 1 : X);
	cout << son << '/' << mom;
	return 0;
}