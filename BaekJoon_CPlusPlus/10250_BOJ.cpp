// ���� 10250�� ACM ȣ��

// Input: 1<= H = ����, W = �� ���� ȣ�� <= 99, 1 <= N <= H*W
// condition: �� �մԵ��� �� ���� �������� ����, ���� �����̶�� ���� ���� ��ȣ

// ������ ���ʺ��� ���ʴ�� �׾ƿö󰣴�.

#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int* Hs = new int[T];
	int* Ws = new int[T];
	int* Ns = new int[T];

	for (int i = 0; i < T; i++)
		cin >> Hs[i] >> Ws[i] >> Ns[i];

	for (int i = 0; i < T; i++)
	{
		int row = (Ns[i] % Hs[i] == 0 ? Ns[i] / Hs[i] : Ns[i] / Hs[i] + 1);
		int floor = (Ns[i] % Hs[i] == 0 ? Hs[i] : Ns[i] % Hs[i]);
		cout << floor * 100 + row << endl;
	}
	delete[] Hs;
	delete[] Ws;
	delete[] Ns;
}