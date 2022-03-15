// ���� 1258�� ���� ������

// input: ����� �� ���� ���� N (1 <= N <= 20, �ڿ���)
//		  �� ���� ������ ���� (H = �ո�, T = �޸�)

// condition: ������ ����: 1���� �� �Ǵ� ���� �ִ� ��� �������� �����´�.

// output: �ּ����� �޸鸸 ���̵��� ���� ��, �ּ����� �޸� ������ ��

// 1x1, 2x2, 3x3 ������ ���� �������� �����Ѵ�.
// ���� ��� (0,0), (0..1, 0..1) �̷� ���̴�.
// �ٸ�, ������ ������ ������ ���� �ʰ� �ϱ� ���ؼ�, i��° ��� ���� �����´�.
// �̶� ����� ���� 4�����̴�.
//  (1) �� �����´�.
//  (2) �ุ �����´�.
//  (3) ���� �����´�.
//  (4) ��� �� ��� �����´�.
// ���� �ּ��� ������ ������ ���� ��츦 �����Ѵ�.

// �߿��� ���� (0,0)�̴�.
// T��� ������ �� �������� ��, �� ���� �� �ִ�.
// �׷��Ƿ� 4���� ��Ȳ�� ���� ��� ������ ����ؾ� �Ѵ�.

// ���ѽð��� 6���̹Ƿ� ����� �ð��̴�.

#include <iostream>
using namespace std;


int GetNumOfBackWithSwitchingLines(bool** _mat, int _N, int _lineNum, bool _switchRow, bool _switchCol)
{
	int numOfBack = 0;
	if (_switchRow)
	{
		for (int f = 0; f < _N; f++)
			_mat[_lineNum][f] = !_mat[_lineNum][f];
	}
	if (_switchCol)
	{
		for (int i = 0; i < _N; i++)
			_mat[i][_lineNum] = !_mat[i][_lineNum];
	}

	for (int i = 0; i < _lineNum; i++)
	{
		if (!_mat[_lineNum][i]) numOfBack++;
		if (!_mat[i][_lineNum]) numOfBack++;
	}
	if (!_mat[_lineNum][_lineNum]) numOfBack++;

	return numOfBack;
}

int main()
{
	int N;
	cin >> N;
	
	// true = front, false = back
	bool** originMat = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		originMat[i] = new bool[N];
		string inputRow;
		cin >> inputRow;
		for (int f = 0; f < N; f++)
			originMat[i][f] = (inputRow[f] == 'H');
	}

	// tempMat for each case
	bool** tempMat = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		tempMat[i] = new bool[N];
	}

	int min = N * N + 1;

	for (int t = 0; t < 4; t++)
	{
		// initiate tempMat for new case
		for (int i = 0; i < N; i++)
			for (int f = 0; f < N; f++)
				tempMat[i][f] = originMat[i][f];

		int numOfBack = 0;

		if (t == 0)		// (0, 0) not changed
		{
			numOfBack += GetNumOfBackWithSwitchingLines(tempMat, N, 0, false, false);
		}
		else if (t == 1)	// Change row and col
		{
			numOfBack += GetNumOfBackWithSwitchingLines(tempMat, N, 0, true, true);
		}
		else if (t == 2)	// Change only row
		{
			numOfBack += GetNumOfBackWithSwitchingLines(tempMat, N, 0, true, false);
		}
		else if (t == 3)	// Change only col
		{
			numOfBack += GetNumOfBackWithSwitchingLines(tempMat, N, 0, false, true);
		}

		int numOfBackInEachCase[4]{ 0 };
		for (int i = 1; i < N; i++)
		{
			numOfBackInEachCase[0] = GetNumOfBackWithSwitchingLines(tempMat, N, i, false, false);
			GetNumOfBackWithSwitchingLines(tempMat, N, i, false, false);	// reset
			
			numOfBackInEachCase[1] = GetNumOfBackWithSwitchingLines(tempMat, N, i, true, true);
			GetNumOfBackWithSwitchingLines(tempMat, N, i, true, true);	// reset

			numOfBackInEachCase[2] = GetNumOfBackWithSwitchingLines(tempMat, N, i, true, false);
			GetNumOfBackWithSwitchingLines(tempMat, N, i, true, false);	// reset

			numOfBackInEachCase[3] = GetNumOfBackWithSwitchingLines(tempMat, N, i, false, true);
			GetNumOfBackWithSwitchingLines(tempMat, N, i, false, true);	// reset

			int tempMin = N * N + 1;
			int minIdx = -1;
			for (int k = 0; k < 4; k++)
			{
				if (tempMin > numOfBackInEachCase[k])
				{
					tempMin = numOfBackInEachCase[k];
					minIdx = k;
				}
			}

			if (minIdx == 0)
			{
				numOfBack += GetNumOfBackWithSwitchingLines(tempMat, N, i, false, false);
			}
			else if (minIdx == 1)
			{
				numOfBack += GetNumOfBackWithSwitchingLines(tempMat, N, i, true, true);
			}
			else if (minIdx == 2)
			{
				numOfBack += GetNumOfBackWithSwitchingLines(tempMat, N, i, true, false);
			}
			else if (minIdx == 3)
			{
				numOfBack += GetNumOfBackWithSwitchingLines(tempMat, N, i, false, true);
			}
		}
		
		if (min > numOfBack) min = numOfBack;
	}

	cout << min;





	for (int i = 0; i < N; i++)
	{
		delete[] originMat[i];
		delete[] tempMat[i];
	}
	delete[] originMat;
	delete[] tempMat;
}
