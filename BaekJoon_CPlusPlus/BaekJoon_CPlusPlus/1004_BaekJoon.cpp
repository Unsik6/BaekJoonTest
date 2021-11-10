// ���� 1004�� � ���� Ǫ����

// Input: T = �׽�Ʈ ���̽��� ����, n = �༺���� ����
//		  (x1, y2) = ����� ��ǥ, (x2, y2) = ������ ��ǥ
//		  (Cx, Cy, r) = �༺���� �߽��� ��ǥ�� ������

// condition: �༺�� ����/��Ż�� �ּ������� �ϴ� ���
//			  1) �༺��� �����ϰų� ������ �ʴ´�.
//			  2) �����/�������� �༺���� ��迡 �ִ� ���, ����/��Ż�� �������� �ʴ´�.
//			  (����) -1000 <= x1, y1, x2, y2, Cx, Cy <= 1000
//			  (����) 1 <= r <= 1000, 1 <= n <= 50

// ���� 1)�� ���Ͽ� �༺�� ���� �̵� �߿��� ����/��Ż�� �߻����� �ʴ´�.
// ��, ������� �������� � ���� ���� ���Ͽ� �Ȱ� ������ ������ ��쿡�� ����/��Ż�� �߻��Ѵ�.

// ��ǥ��� �������� ���ǿ� ���Ͽ�, ���� �������� ������ ����� �ִ밡 2*10^6�̴�. int ����

#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int arrPoslen = T * 4;
	int* arrPos = new int[arrPoslen];					// ��� ������� ������ ��ǥ
	int* arrSystemCnt = new int[T];						// ��� �༺�� ����
	int*** arrSystems = new int**[T];					// ��� �༺�� ����: 1���� = test, 2���� = �༺��, 3���� = �༺�� ����

	for (int t = 0; t < T; t++)
	{
		cin >> arrPos[4 * t] >> arrPos[1 + 4 * t]
			>> arrPos[2 + 4 * t] >> arrPos[3 + 4 * t];
		cin >> arrSystemCnt[t];
		arrSystems[t] = new int* [arrSystemCnt[t]];
		for (int s = 0; s < arrSystemCnt[t]; s++)
		{
			arrSystems[t][s] = new int[3];
			cin >> arrSystems[t][s][0] >> arrSystems[t][s][1]
				>> arrSystems[t][s][2];
		}

		int otherCnt{ 0 };
		for (int s = 0; s < arrSystemCnt[t]; s++)
		{
			bool IsStartIn{ false }, IsEndIn{ false };
			int tmpStartXfunct = arrSystems[t][s][0] - arrPos[4 * t];
			int tmpStartYfunct = arrSystems[t][s][1] - arrPos[1 + 4 * t];
			int tmpEndXfunct = arrSystems[t][s][0] - arrPos[2 + 4 * t];
			int tmpEndYfunct = arrSystems[t][s][1] - arrPos[3 + 4 * t];

			if (tmpStartXfunct * tmpStartXfunct +
				tmpStartYfunct * tmpStartYfunct < arrSystems[t][s][2] * arrSystems[t][s][2])
				IsStartIn = true;
			if (tmpEndXfunct * tmpEndXfunct +
				tmpEndYfunct * tmpEndYfunct < arrSystems[t][s][2] * arrSystems[t][s][2])
				IsEndIn = true;
			if (IsStartIn != IsEndIn) otherCnt++;
		}

		cout << otherCnt << "\n";
	}

	delete[] arrPos, arrSystemCnt;
	for (int i = 0; i < T; i++)
		delete[] arrSystems[i];
	delete[] arrSystems;

	return 0;
}