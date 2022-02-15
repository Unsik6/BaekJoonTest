// ���� 1149�� RGB�Ÿ�

// input: 1 <= N = ���� ���� <= 1,000 (�ڿ���)
//		  �� �ٿ� ������ R, G, B�� ĥ�ϴ� ���� (1 <= x <= 1,000) (�ڿ���)

// condition: ��� ���� ĥ�ϴ� ����� �ּҰ�
//			  ���� �پ��ִ� ���� ���� �ٸ� ���̾�� �Ѵ�.

// DP�� Ǯ�� N��° �������� �ּ� �� ������
// N��° ���� x��� ���� ĥ�� ��, N-1��° ���� x�� �ƴ� �ٸ� ���� ĥ�� �ּҰ��� N��° ���� x��� ���� ĥ�ϴ� ������
// ���� �� �� �ּ� ���� ����.

#include <iostream>
using namespace std;

int min(int _a, int _b)
{
	return (_a < _b ? _a : _b);
}

int main()
{
	int N;
	cin >> N;

	// the prices of painting each color for each house
	int**rgbArr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		rgbArr[i] = new int[3];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> rgbArr[i][0] >> rgbArr[i][1] >> rgbArr[i][2];
	}
		
	// optimal solution memoziation array
	int** solution = new int*[N];
	for (int i = 0; i < N; i++)
		solution[i] = new int[3];

	// save the prices for the first house
	for(int i = 0; i < 3; i++)
		solution[0][i] = rgbArr[0][i];

	// solute subproblems
	for (int i = 1; i < N; i++)
	{
		for (int f = 0; f < 3; f++)
		{
			solution[i][f] = min(solution[i - 1][(f+1) % 3] + rgbArr[i][f],
				solution[i - 1][(f + 2) % 3] + rgbArr[i][f]);
		}
	}

	// optimal solution
	int optimalSolution = min(solution[N - 1][0], solution[N - 1][1]);
	optimalSolution = min(optimalSolution, solution[N - 1][2]);
	cout << optimalSolution;

	for (int i = 0; i < N; i++)
		delete[] rgbArr[i];
	delete[] rgbArr;
	for (int i = 0; i < N; i++)
		delete[] solution[i];
	delete[] solution;
}