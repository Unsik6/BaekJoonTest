/* ���� 3048�� ����
*
* Input: �������� N1�� N2�� ���� ��
*		 N1�� ����
*		 N2�� ����
*		 (�� ���̴� ���ĺ� �빮�ڷ� ǥ��, ���� �׷� �� �ߺ� ����)
*		 (0 <= T <= 50)

* Output: T�� �� ���̵��� ����
*		  N1�� ����->������, N2�� ���� �ݴ�� �̵��Ѵ�.
*		  ���̴� �ڽ� �տ� ���� ���� ���̰� ���� �� �����Ѵ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n1, n2, t;
	cin >> n1 >> n2;
	vector<pair<char, int>> vec;
	string str;
	cin >> str;
	for (int i = n1 - 1; i >= 0; i--) vec.push_back(make_pair(str[i], 0));
	cin >> str;
	for (int i = 0; i < n2; i++) vec.push_back(make_pair(str[i], 1));

	cin >> t;
	int time = 0;
	while (time != t)
	{
		for (int i = 0; i < n1 + n2 - 1; i++)
		{
			if (vec[i].second == 0 && vec[i + 1].second == 1)
			{
				swap(vec[i], vec[i + 1]);
				i++;
			}
		}
		time++;
	}

	for (int i = 0; i < n1 + n2; i++)
		cout << vec[i].first;
}