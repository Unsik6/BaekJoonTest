// ���� 2869�� �����̴� �ö󰡰� �ʹ�.

// Input: 1 <= B = �̲����� <= A = �ö� <= V = ��ǥ <=1,000,000,000
// condition: ������ A��ŭ �ö󰡰� �㿡�� B ��ŭ �̲�������.

#include<iostream>
using namespace std;

int main()
{
	int A, B, V;
	cin >> A >> B >> V;
	cout << ((V - B) % (A - B) == 0 ? (V - B) / (A - B) : ((V - B) / (A - B) + 1));
}