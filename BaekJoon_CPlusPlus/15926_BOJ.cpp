/* ���� 15926�� ������ ��ȣ���̾�!!
*
* Input: ���ڿ��� ���� n (1 <= n <= 200,000)
*		 ���ڿ�

* Output: �ùٸ� ��ȣ ���ڿ��� �ִ� ����
*		  1) ()�� �ùٸ� ��ȣ���ڿ��̴�.
*		  2) � ���ڿ� x�� �ùٸ� ��ȣ ���ڿ��̶��, (x)�� �ùٸ� ��ȣ ���ڿ��̴�.
*		  3) � ���ڿ� x�� y�� �ùٸ� ��ȣ ���ڿ��̶��, xy�� �ùٸ� ��ȣ ���ڿ��̴�.
*
* (�� �ε����� ���ÿ� �ְ� )�� ���� �� pop�Ѵ�.
* �ùٸ� ���ڿ� ���ʿ��� �߻��� �ùٸ� ���ڿ��� �ٱ����� ���� �� ����.
*/

#include <iostream>
#include <stack>
using namespace std;

int n;
string str;
stack<int> stk;

int main() {
	cin >> n >> str;
	stk.push(-1);
	int maximum = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '(')
		{
			stk.push(i);
		}
		else {
			stk.pop();
			if (!stk.empty())
			{
				maximum = max(maximum, i - stk.top());
			}
			else stk.push(i);
		}
	}
	cout << maximum;
}