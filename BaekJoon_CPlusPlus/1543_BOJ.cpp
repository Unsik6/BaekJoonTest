/* ���� 1543�� ���� �Ÿ�
*
* Input: �� ���� ���ڿ� (1 <= |text| <= 2500) (1 <= |pattern| <= 50)
*
* Output: �ߺ����� �ʰ� pattern�� text���� ��Ÿ���� Ƚ��
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text, pattern;

	getline(cin, text);
	getline(cin, pattern);

	int cnt = 0;
	int pos = 0;
	int anchor = -1000000;
	while (1)
	{
		pos = text.find(pattern, pos);
		if (pos == -1) break;
		if (anchor + (int)pattern.length() - 1 < pos)
		{
			cnt++;
			anchor = pos;
			pos++;
		}
		else
			pos++;

	}

	cout << cnt;
}