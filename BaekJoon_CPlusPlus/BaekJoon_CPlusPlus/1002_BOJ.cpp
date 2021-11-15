// ���� 1002�� �ͷ�

#include <iostream>
#include <cmath>
using namespace std;

int InCircle(int, int, int, int, int, int);



int main()
{
	int T;
	cin >> T;

	int** pos = new int* [T];
	for (int i = 0; i < T; i++)
		pos[i] = new int[6];

	for (int i = 0; i < T; i++)
		cin >> pos[i][0] >> pos[i][1] >> pos[i][2] >> pos[i][3] >> pos[i][4] >> pos[i][5];

	for (int i = 0; i < T; i++)
	{
		int count = 0;
		count = InCircle(pos[i][0], pos[i][1], pos[i][2], pos[i][3], pos[i][4], pos[i][5]);
		cout << count << endl;
	}

	for (int i = 0; i < T; i++)
		delete[] pos[i];
	delete[] pos;

	return 0;
}

int InCircle(int _x1, int _y1, int _r1, int _x2, int _y2, int _r2)
{
	double dis = sqrt(pow(_x2 - _x1, 2) + pow(_y2 - _y1, 2));
	// ���� �߽��� ���� ��
	if (dis == 0)
		return (_r1 == _r2 ? -1 : 0);
	// �߽� �� �Ÿ��� �������� �պ��� Ŭ ��
	else if (dis > _r1 + _r2) return 0;
	// ������ ��
	else if (dis == _r1 + _r2) return 1;
	// ������ ��
	else if (_r1 > _r2)
	{
		if (dis + _r2 == _r1) return 1;
		if (dis + _r2 < _r1) return 0;
		if (dis + _r2 > _r1) return 2;
	}
	else if (_r1 < _r2)
	{
		if (dis + _r1 == _r2) return 1;
		if (dis + _r1 < _r2) return 0;
		if (dis + _r1 > _r2) return 2;
	}
	else if (_r1 == _r2) return 2;
}