// ���� 1712�� ���ͺб���

// Input: 1 <= A = �������, B = �������, C = ���� <= 21��
// condition: ���ͺб����� ��Ÿ���� ������ -1

#include<iostream>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	if (B >= C) cout << -1;
	else cout << A / (C - B) + 1;
	return 0;	
}