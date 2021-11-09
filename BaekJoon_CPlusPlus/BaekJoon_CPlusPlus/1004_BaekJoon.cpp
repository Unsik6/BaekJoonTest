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
// ��, ������� �������� ��� ���Ե� �踦 ã�� ��,
// ������� �������� ���Ͽ� ���� �󸶳� ����� �ִ����� �����Ѵ�.
// �׸��� �� ���� �����ش�.

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
	int** arrSystems = new int*[T];						// ��� �༺�� ����

	for (int i = 0; i < T; i++)
	{
		cin >> arrPos[4 * i] >> arrPos[1 + 4 * i]
			>> arrPos[2 + 4 * i] >> arrPos[3 + 4 * i];
		cin >> arrSystemCnt[i];
		int SystemInfoCnt = 3 * arrSystemCnt[i];
		arrSystems[i] = new int[SystemInfoCnt];
		for (int f = 0; f < arrSystemCnt[i]; f++)
		{
			int SystemNInfo = 3 * f;
			cin >> arrSystems[i][SystemNInfo] >> arrSystems[i][1 + SystemNInfo]
				>> arrSystems[i][2 + SystemNInfo];
			cout << f << "��° ����: " << arrSystems[i][SystemNInfo]
				<< " " << arrSystems[i][1 + SystemNInfo]
				<< " " << arrSystems[i][2 + SystemNInfo];
		}
	}

	for (int i = 0; i < T; i++)
	{
		int startPosLevel{ 0 }, endPosLevel{ 0 };
		for (int f = 0; f < arrSystemCnt[i]; f++)
		{
			bool IsStartIn{ false }, IsEndIn{ false };
			int tmpStartXfunct = arrSystems[i][3 * f] - arrPos[4 * i];
			int tmpStartYfunct = arrSystems[i][1 + 3 * f] - arrPos[1 + 4 * i];
			int tmpEndXfunct = arrSystems[i][3 * f] - arrPos[2 + 4 * i];
			int tmpEndYfunct = arrSystems[i][1 + 3 * f] - arrPos[3 + 4 * i];

			if (tmpStartXfunct * tmpStartXfunct + tmpStartYfunct * tmpStartYfunct < arrSystems[i][2 + 3 * f])
			{
				startPosLevel++;
				IsStartIn = true;
			}
			if (tmpEndXfunct * tmpEndXfunct + tmpEndYfunct * tmpEndYfunct < arrSystems[i][2 + 3 * f])
			{
				endPosLevel++;
				IsEndIn = true;
			}
			if (IsStartIn * IsEndIn != 0) break;
		}

		cout << startPosLevel + endPosLevel << "\n";
	}

	delete[] arrPos, arrSystemCnt;
	for (int i = 0; i < T; i++)
		delete[] arrSystems[i];
	delete[] arrSystems;
}