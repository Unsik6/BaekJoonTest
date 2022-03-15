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

// �߿��� ���� (i, i)�̴�.
// ���� ���� ������, ���� ���� �����Ŀ� ����
// �� ���� ������ ���� ������ �޶��� �� �ִ�.

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

	int numOfBack = 0;
	for (int i = 0; i < N; i++)
	{
		
	}






	for (int i = 0; i < N; i++)
	{
		delete[] originMat[i];
	}
	delete[] originMat;
}
