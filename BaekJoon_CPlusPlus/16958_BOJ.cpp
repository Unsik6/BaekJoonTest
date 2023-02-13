/* ���� 16958 �ڷ���Ʈ
*
*Input: ������ �� N (2 <= N <= 1,000)
*		�ڷ���Ʈ ��� T (1 <= T <= 2,000)
*		�ִ� ������� Ƚ�� M (1 <= M <= 1,000)
*		i��° ������ ���� s_i, x_i, y_i (s = (is 0 ? �Ϲݵ��� : Ư������), 0 <= x_i, y_i <= 1,000)
*		�� ������ ��ǥ�� ���� ���� ����.
*		������ ���ð� ���� ��쵵 ����

* Output: �� ������ ���
*/


#include <iostream>
#include <utility>

using namespace std;

// Input
int N, M, T;
pair<int, int> pos[1001];
bool isSpecial[1001];

// functions
int costOfMove(int _a, int _b)
{
	int mD = abs(pos[_a].first - pos[_b].first) + abs(pos[_a].second - pos[_b].second);
	if (isSpecial[_a] && isSpecial[_b])
		return min(mD, T);
	// Manhattan distance
	else
		return mD;
}

// Floyd-Warshell
int mat[1001][1001]{ 0 };
void constructFWMat()
{
	for (int k = 0; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			if (i == k) continue;
			for (int j = 1; j <= N; j++)
			{
				if (i == j || j == k) continue;
				// �ʱ�ȭ
				if (!mat[i][j])
					mat[i][j] = costOfMove(i, j);
				else
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}

void input()
{
	cin >> N >> T;
	for (int n = 1; n <= N; n++)
		cin >> isSpecial[n] >> pos[n].first >> pos[n].second;
}

void wholeQuery()
{
	cin >> M;
	for (int m = 0; m < M; m++)
	{
		int a, b;
		cin >> a >> b;
		cout << mat[a][b] << '\n';
	}
}


int main()
{
	input();
	constructFWMat();
	wholeQuery();
	return 0;
}