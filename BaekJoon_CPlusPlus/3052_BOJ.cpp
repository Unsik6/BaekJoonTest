/* ���� 3052�� ������
*
* Input: 10���� �� (1 <= i <= 1,000)

* Output: 10���� ���� 42�� ���� ���������� �����ϴ� �ߺ����� �ʴ� ���� ����
*/

#include <iostream>
int main()
{
	bool arr[42]{false}; int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		int x;
		std::cin >> x;
		if (arr[x % 42]) continue;
		arr[x % 42] = true;
		cnt++;
	}
	std::cout << cnt;
}