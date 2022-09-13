/* ���� 11758�� CCW
*
* Input: �� P1~P3�� ��ǥ�� �ٷ� �����Ͽ� �Է� ����.
*		 -10,000 <= x1,y1,x2,y2,x3,y3 <= 10,000

* Output: P1 - P2 - P3�� ������� ���� ������ �ݽð� �����̸� 1, �ð� �����̸� -1, �������̸� 0�� ���
*
* ���� P1�� �������� P2�� P3�� ������ ������ �ݽð� ����, ������ ������ �ð� �����̴�. (�����ϴ� ������ ���� ����)
* �̴� [P1->P2] ����(v1)�� [P1->P3] ����(v2)�� �������� �Ǵ��� �� �ִ�.
* �� ������ ������ ����� ���⿡ ���� �����ȴ�.
*/

#include<iostream>
#include<utility>
using namespace std;

#define position pair<int, int>

position operator- (const position _left, const position _right)
{
	return { _left.first - _right.first, _left.second - _right.second };
}

int ccw(position _p1, position _p2, position _p3)
{
	position v1 = _p2 - _p1;
	position v2 = _p3 - _p1;

	int cross = v1.first * v2.second - v1.second * v2.first;

	if (cross > 0) return 1;
	else if (cross < 0) return -1;
	else return 0;
}

int main()
{
	position positions[3];
	for (int i = 0; i < 3; i++)
		cin >> positions[i].first >> positions[i].second;
	cout << ccw(positions[0], positions[1], positions[2]);
}