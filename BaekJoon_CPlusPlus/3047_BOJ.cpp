/* ���� 3047�� ABC
*
* Input: 1 <= x, y, z <= 100
*		  A, B, C�� �̷���� ���ڿ�
*

* Output: A < B < C��� ������ ABC�� x,y,z�� �����ϰ� �Էµ� ���ڿ��� ���� ���� ���
*/

#include <iostream>
#include <algorithm>
int main()
{
	int arr[3]; char str[4];
	for (int i = 0; i < 3; i++) std::cin >> arr[i];
	std::sort(arr, arr + 3);
	std::cin >> str;
	for (int i = 0; i < 3; i++)
	{
		if (str[i] == 'A') std::cout << arr[0];
		else if (str[i] == 'B') std::cout << arr[1];
		else std::cout << arr[2];
		std::cout << ' ';
	}
}