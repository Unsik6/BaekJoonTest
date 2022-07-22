// ���� 1018�� ü���� �ٽ� ĥ�ϱ�

// input: 8 <= (M, N) <= 50
//		  ���� �� ������ ��

// condition: 8*8 ü�� �������� ���� �� ĥ�ؾ� �ϴ� �ּ� ��

// ���Ʈ���� �˰���: ������ �Ǵ�, ���ǹ��� ���̽����� ��� �˻��ϴ� ���̴�.
// ü������ ����� 2���� ��츦 �����ϰ�, if���� ���� ���Ѵ�.
// ���� ���ϴ� ����ĭ(�»�� ����)�� B��� B�� �����ϴ� ����� ü������,
// �ƴ϶�� W�� �����ϴ� ����� ü������ �˻��Ѵ�.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// set the sample board
	char** bBoard = new char*[8];
	char** wBoard = new char* [8];
	bool checkForFor = false;
	for (int i = 0; i < 8; i++)
	{
		checkForFor = !checkForFor;
		bBoard[i] = new char[8];
		wBoard[i] = new char[8];
		for (int f = 0; f < 8; f++)
		{
			if (checkForFor)
			{
				bBoard[i][f] = 'B';
				wBoard[i][f] = 'W';
			}
			else
			{
				bBoard[i][f] = 'W';
				wBoard[i][f] = 'B';
			}
			checkForFor = !checkForFor;
		}
	}

	int N, M;
	cin >> N >> M;
	char** board = new char* [N];
	for (int i = 0; i < N; i++)
	{
		board[i] = new char[M];
		for (int f = 0; f < M; f++)
			cin >> board[i][f];
	}
	
	vector<int> v_cnt;	// save the counts of cases
	for (int i = 0; i < N - 7; i++)
	{
		for (int f = 0; f < M - 7; f++)
		{
			for (int bw = 0; bw < 2; bw++)
			{
				char** target = (bw == 0 ? bBoard : wBoard);
				int countOfCase = 0;
				// compare target(sample board) and the part of board started with (i, f)
				for (int k = 0; k < 8; k++)
					for (int j = 0; j < 8; j++)
						if (board[i + k][f + j] != target[k][j]) countOfCase++;
				v_cnt.push_back(countOfCase);
			}
		}
	}
	int min = v_cnt[0];
	for (int& v : v_cnt)
		min = (min > v ? v : min);
	cout << min;
}
