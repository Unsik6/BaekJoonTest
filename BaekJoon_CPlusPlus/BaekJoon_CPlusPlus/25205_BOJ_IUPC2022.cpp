/* ���� 25205�� ��δ���ũ 2077
*
* Input: ù ��° �ٿ� ���ڿ� s�� ���̸� ��Ÿ���� ���� N (2 <= N <= 30)
*		 �� ��° �ٿ� ���ڿ� s
*
* Output: ����� �̸� ������ ���ڿ� ��ħ�� �ִٸ� 1, ���ٸ� 0
*
*/

#include <iostream>
using namespace std;

int main()
{
	int N; string str;
	cin >> N >> str;
	if (str[N - 1] == 'r' || str[N - 1] == 'R' || str[N - 1] == 't' || str[N - 1] == 's'
		|| str[N - 1] == 'w' || str[N - 1] == 'g' || str[N - 1] == 'e' || str[N - 1] == 'f'
		|| str[N - 1] == 'a' || str[N - 1] == 'q' || str[N - 1] == 'x' || str[N - 1] == 'v'
		|| str[N - 1] == 'T' || str[N - 1] == 'd' || str[N - 1] == 'c' || str[N - 1] == 'z')
	{
		cout << 1;
	}
	else cout << 0;
	return 0;
}