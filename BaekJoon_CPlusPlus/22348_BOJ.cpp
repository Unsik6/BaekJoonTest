/* ���� 22348 ��� ������
*
* Input: �׽�Ʈ ���̽� �� T (1 <= T <= 10,000)
*		 ��������Ʈ a��, �Ķ�����Ʈ b�� (1 <= a, b <= 50,000)

* Output: ���� �� �ִ� ��� ������ ����
*/

#include <iostream>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.tie(NULL);

const int M = 1'000'000'007;

// input & output
int T, redPaint, bluePaint, caseNum;

// DP: maxRadiusByRedUse[maximum_radius][red paint usage]
#define MAX_R 502
#define MAX_PAINT 50000
int maxRadiusByRedUse[MAX_R + 1][MAX_PAINT + 1]{ 0 };
int sumOfCase[MAX_R + 1][MAX_PAINT + 1]{ 0 };

// preprocessing
void createDP()
{
	// base case [0][0]
	maxRadiusByRedUse[0][0] = 1;

	// ���� ���̽��� �������� ���� �� �ִ� [���� �� �߰� ���̽�]�� ����� ���� �߰�
	// ���� �ϳ� �þ �� ���� ������ ����ϴ°� �� �ϴ°��� ���� �ٸ���.
	// 1) ���� ���� �׸� �� �ִ� ���
	//		���� ���̽����� ���� ũ�⸸ŭ �� �� �� �ִٸ� ������ ����� ���� �߰����ش�.
	// 2) ���� ���� �׸� �� ���� ���
	//		���� ��뷮 ��ŭ�� �߰����ش�.
	// �� ���̽��� �����̴�. (���� ����Ʈ���� ����)
	for (int r = 0; r < MAX_R; r++)
	{
		for (int useRed = 0; useRed <= MAX_PAINT; useRed++)
		{
			// case 1: ���� ���� �������� �׸� �� ����.
			if (useRed + r + 1 <= MAX_PAINT)
			{
				maxRadiusByRedUse[r + 1][useRed + r + 1] += maxRadiusByRedUse[r][useRed];
				maxRadiusByRedUse[r + 1][useRed + r + 1] %= M;
			}

			// case 2: ���� ���� ���� ����Ʈ �� ������
			maxRadiusByRedUse[r + 1][useRed] += maxRadiusByRedUse[r][useRed];
			maxRadiusByRedUse[r + 1][useRed] %= M;
		}
	}

	// ������ ���� ��ó��
	for (int r = 0; r <= MAX_R; r++)
	{
		sumOfCase[r][0] = maxRadiusByRedUse[r][0];
		for (int useRed = 1; useRed <= MAX_PAINT; useRed++)
			sumOfCase[r][useRed] = (sumOfCase[r][useRed - 1] + maxRadiusByRedUse[r][useRed]) % M;
	}
}

int main()
{
	FAST_IO
		createDP();
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		caseNum = 0;					// output initialization
		cin >> redPaint >> bluePaint;	// input

		for (int r = 1; r <= MAX_R; r++)
		{
			// ����� �� ����Ʈ ��
			int totalUsage = r * (r + 1) / 2;

			// ���� ����Ʈ �ּ� ��뷮 ~ �ִ� ��뷮������ �� ���ϱ�
			// ���� ����Ʈ �ּ� ��뷮 = �� ��뷮 - �Ķ� ����Ʈ ��ü ���
			// ���� ����Ʈ �ִ� ��뷮 = ���� ����Ʈ ��ü ���
			int minRed = totalUsage - bluePaint;

			// ���� �� ���� ���̽��̴�.
			// ��: 3���� �� = 6�� ���, �Ķ� ����Ʈ 2��, ���� ����Ʈ 3��
			//	   �ּ� ����� 4���̹Ƿ� ���� �� ����.
			if (minRed > redPaint)
				continue;

			int sumRed;
			if (minRed > 0)
				sumRed = (sumOfCase[r][redPaint] - sumOfCase[r][minRed - 1] + M) % M;
			else
				sumRed = sumOfCase[r][redPaint];

			caseNum += sumRed;
			caseNum %= M;
		}

		cout << caseNum << '\n';
	}
	return 0;
}