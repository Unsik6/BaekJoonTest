// ���� 10872�� ���丮��

// input: 0<= N <= 12

// N! = 479,001,600�̹Ƿ� int�� �ص� �ȴ�.

#include <iostream>
using namespace std;
int factorial(int n)
{
	if (n <= 1) return 1;
	else return n * factorial(n - 1);
}
int main()
{
	int n;
	cin >> n;
	cout << factorial(n);
}