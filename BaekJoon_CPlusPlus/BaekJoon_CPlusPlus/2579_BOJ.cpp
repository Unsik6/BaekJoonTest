// ���� 2579�� ��� ������

// input: 1 <= n = �־����� ����� �� <= 300 (�ڿ���)
//		  �� ����� ����. (1 <= x <= 10000) (�ڿ���)

// condition: 1) �ѹ��� 1�� �Ǵ� 2���� ��� ������ ����
//			  2) ���ӵ� 3���� ����� ��� ���� �� ����.
//			  3) ù��°�� ������� ������� ����. ������ ����� ������ ��ƾ� ��.

// �� ������ �ִ��� ����϶�.

// �ϳ��� problem�� ������ 2ĭ ���̳� 1ĭ ���̳��̴�.
// 1ĭ ���� ��쿡�� ���� ĭ���� 1ĭ�� �ǳ� ���� �� �� ����.
// 2ĭ ���� ��쿡�� 2ĭ ������ ĭ���� �ִ밪�� �������� �ȴ�.

// 3��¥�� �迭�� �����Ѵ�.
// arr[n][0]�� �� ĭ�� �����̴�.
// arr[n][1]�� 1ĭ ���� ���
// arr[n][2]�� 2ĭ ���� ����̴�.

#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int** stairsNScores = new int*[n + 1];

	for (int i = 0; i < n + 1; i++)
	{
		stairsNScores[i] = new int[3];
	}
	for (int i = 0; i < 3; i++)
	{
		stairsNScores[0][i] = 0;
	}
	for (int i = 1; i < n + 1; i++)
	{
		cin >> stairsNScores[i][0];
		if (i == 1)
		{
			for (int f = 1; f < 3; f++) stairsNScores[i][f] = stairsNScores[i][0];
		}
		else
		{
			stairsNScores[i][1] = stairsNScores[i][0] + stairsNScores[i - 1][2];
			stairsNScores[i][2] = stairsNScores[i][0] +
				(stairsNScores[i - 2][1] > stairsNScores[i - 2][2] ? stairsNScores[i - 2][1] : stairsNScores[i - 2][2]);
		}
	}

	cout << (stairsNScores[n][1] > stairsNScores[n][2] ? stairsNScores[n][1] : stairsNScores[n][2]);
}