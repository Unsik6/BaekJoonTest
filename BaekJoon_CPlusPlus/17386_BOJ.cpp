/* ���� 17386�� ���� ����1
*
* Input: ���� L1�� L2�� �� ������ ��ǥ�� �ٷ� �����Ͽ� �Է� ����.
*		 -1,000,000 <= x1, y1, x2, y2, x3, y3, x4, y4 <= 1,000,000
*		 ��ǥ�� ������ ��� ����

* Output: L1�� L2�� �����ϸ� 1, �ƴϸ� 0
*		  ��, ������ ���̴� �ݵ�� 0���� ũ��.
*		  ��, �� ���� ������ �� �ִ� ���� ����.
*
* CCW �����̴�.
* Pi = (xi, yi)��� ���� ��,
* P1�� P3, P4�� CCW�� ���, P2�� P3, P4�� CCW�� ����� �ٸ� ��쿡�� P1�� P2�� L2�� �������� ���� �ٸ� �ʿ� �����Ѵٴ� ���� �ǹ��Ѵ�.
* ����, �� ������ P3�� P4 �������ε� ����� �Ѵ�.
*/

#include<iostream>
#include<utility>
using namespace std;

// (10^6)^2�� int ���� �ʰ��Ͽ� ����
#define position pair<long long, long long>

position operator- (const position _left, const position _right)
{
	return { _left.first - _right.first, _left.second - _right.second };
}

int ccw(position _p1, position _p2, position _p3)
{
	position v1 = _p2 - _p1;
	position v2 = _p3 - _p1;

	long long cross = v1.first * v2.second - v1.second * v2.first;

	if (cross > 0) return 1;
	else if (cross < 0) return -1;
	else return 0;
}

// �Ű������� ccw ����� �Է�, �̶� �� ����� ���� -1�̶�� ���� ������ �ٸ���.
bool isCross(int _a, int _b)
{
	return _a * _b == -1;
}

int main()
{
	position positions[4];
	for (int i = 0; i < 4; i++)
		cin >> positions[i].first >> positions[i].second;
	cout << (isCross(ccw(positions[0], positions[2], positions[3]), ccw(positions[1], positions[2], positions[3])) &&
		isCross(ccw(positions[2], positions[0], positions[1]), ccw(positions[3], positions[0], positions[1])));
}