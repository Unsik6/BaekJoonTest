// ���� 1463�� 1�� �����

// input: 1 <= X <= 10^6 (����)

// condition: 1) X�� 3���� ������ �������� 3���� ������.
//			  2) X�� 2�� ������ �������� 2�� ������.
//			  3) 1�� ����.


#include<iostream>
using namespace std;

int main()
{
	int X;
	cin >> X;
	int* arr = new int[X + 1];
	if (X == 1) cout << 0;
	else if (X == 2) cout << 1;
	else if (X == 3) cout << 1;
	else if (X >= 4)
	{
		arr[2] = 1;
		arr[3] = 1;
		int cnt = 4;
		while (cnt <= X)
		{
			arr[cnt] = arr[cnt - 1] + 1;
			if (cnt % 2 == 0)
				arr[cnt] =(arr[cnt] < arr[cnt / 2] + 1 ? arr[cnt] : arr[cnt / 2] + 1);
			if (cnt % 3 == 0)
				arr[cnt] = (arr[cnt] < arr[cnt / 3] + 1 ? arr[cnt] : arr[cnt / 3] + 1);
			cnt++;
		}
		
		cout << arr[X] << '\n';

		delete[] arr;
	}
}