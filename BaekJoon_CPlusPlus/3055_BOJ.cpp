/* ���� 3055�� Ż��
*
* Input: R, C (1 <= R, C <= 50)
*		 R���� �ٿ� ���� (��, S, D�� �� ����)

* Output: (1) S���� ����Ͽ� D�� �����ϴ� ���� ���� �ð� ��� (�� ����� KAKTUS ���)
*		  (2) �̵����� 1�� �ð��� �ҿ�ȴ�.
*		  (3) ����ġ�� ���� ������ ĭ���� �̵��� �� �ִ�.
*		  (4) ���� ���� ������ ��� ĭ���� �����Ѵ�.
*		  (5) ���� ������ �����̰ų� ���� ĭ���� ����ġ�� �̵��� �� ����.
*		  (6) ���� ����� �ұ��� �̵��� �� ����.
*		  (7) ���� ����ġ�� ���� ����� �� ����.
* 
* (1) �ִ� ���
* (2) �� ���� ó������� Output.(5)�� ó���� �� �ִ�.
*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char map[50][50];		// ����
int waterMap[50][50];	// �� ��ġ ���� ���� �������� �ּ� �ð� ����
int hogMap[50][50];		// ����ġ �ִ� ���

struct compWater
{
	bool operator()(pair<int, int> _a, pair<int, int> _b)
	{
		return (waterMap[_a.first, _a.second] < waterMap[_b.first, _b.second]);
	}
};
struct compHog
{
	bool operator()(pair<int, int> _a, pair<int, int> _b)
	{
		return (hogMap[_a.first, _a.second] < hogMap[_b.first, _b.second]);
	}
};

int main()
{
	int R, C;
	cin >> R >> C;

	priority_queue < pair<int, int>, vector<pair<int, int>>, compWater> waters;
	priority_queue < pair<int, int>, vector<pair<int, int>>, compHog> hogs;
	pair<int, int> S, D;

	for (int r = 0; r < R; r++)
	{
		string str;
		cin >> str;
		for (int c = 0; c < C; c++)
		{
			map[r][c] = str[c];
			waterMap[r][c] = 100000;
			hogMap[r][c] = 100000;
			if (str[c] == '*')
			{
				waters.push(make_pair(r, c));
				waterMap[r][c] = 0;
			}
			else if (str[c] == 'S') S = make_pair(r, c);
			else if (str[c] == 'D') D = make_pair(r, c);
		}
	}

	// ���� �� ���� �ּ� ���� �ð� ���
	while (!waters.empty())
	{
		pair<int, int> cur = waters.top();
		waters.pop();

		// ��
		if (cur.first - 1 >= 0)
		{
			if (waterMap[cur.first - 1][cur.second] > waterMap[cur.first][cur.second] + 1
				&& map[cur.first - 1][cur.second] != 'X' && map[cur.first - 1][cur.second] != 'D')
			{
				waterMap[cur.first - 1][cur.second] = waterMap[cur.first][cur.second] + 1;
				waters.push(make_pair(cur.first - 1, cur.second));
			}
		}
		// ��
		if (cur.first + 1 < R)
		{
			if (waterMap[cur.first + 1][cur.second] > waterMap[cur.first][cur.second] + 1
				&& map[cur.first + 1][cur.second] != 'X' && map[cur.first + 1][cur.second] != 'D')
			{
				waterMap[cur.first + 1][cur.second] = waterMap[cur.first][cur.second] + 1;
				waters.push(make_pair(cur.first + 1, cur.second));
			}
		}
		// ��
		if (cur.second - 1 >=  0)
		{
			if (waterMap[cur.first][cur.second - 1] > waterMap[cur.first][cur.second] + 1
				&& map[cur.first][cur.second - 1] != 'X' && map[cur.first][cur.second - 1] != 'D')
			{
				waterMap[cur.first][cur.second - 1] = waterMap[cur.first][cur.second] + 1;
				waters.push(make_pair(cur.first, cur.second - 1 ));
			}
		}
		// ��
		if (cur.second + 1 < C)
		{
			if (waterMap[cur.first][cur.second + 1] > waterMap[cur.first][cur.second] + 1
				&& map[cur.first][cur.second + 1] != 'X' && map[cur.first][cur.second + 1] != 'D')
			{
				waterMap[cur.first][cur.second + 1] = waterMap[cur.first][cur.second] + 1;
				waters.push(make_pair(cur.first, cur.second + 1));
			}
		}
	}

	// ����ġ �ִ� ��� ���ϱ�
	hogMap[S.first][S.second] = 0;
	hogs.push(S);
	while (!hogs.empty())
	{
		pair<int, int> cur = hogs.top();
		hogs.pop();

		// ��
		if (cur.first - 1 >= 0)
		{
			if (hogMap[cur.first - 1][cur.second] > hogMap[cur.first][cur.second] + 1
				&& map[cur.first - 1][cur.second] != 'X'
				&& waterMap[cur.first - 1][cur.second] > hogMap[cur.first][cur.second] + 1)
			{
				hogMap[cur.first - 1][cur.second] = hogMap[cur.first][cur.second] + 1;
				hogs.push(make_pair(cur.first - 1, cur.second));
			}
		}
		// ��
		if (cur.first + 1 < R)
		{
			if (hogMap[cur.first + 1][cur.second] > hogMap[cur.first][cur.second] + 1
				&& map[cur.first + 1][cur.second] != 'X'
				&& waterMap[cur.first + 1][cur.second] > hogMap[cur.first][cur.second] + 1)
			{
				hogMap[cur.first + 1][cur.second] = hogMap[cur.first][cur.second] + 1;
				hogs.push(make_pair(cur.first + 1, cur.second));
			}
		}
		// ��
		if (cur.second - 1 >= 0)
		{
			if (hogMap[cur.first][cur.second - 1] > hogMap[cur.first][cur.second] + 1
				&& map[cur.first][cur.second - 1] != 'X'
				&& waterMap[cur.first][cur.second - 1] > hogMap[cur.first][cur.second] + 1)
			{
				hogMap[cur.first][cur.second - 1] = hogMap[cur.first][cur.second] + 1;
				hogs.push(make_pair(cur.first, cur.second - 1));
			}
		}
		// ��
		if (cur.second + 1 < C)
		{
			if (hogMap[cur.first][cur.second + 1] > hogMap[cur.first][cur.second] + 1
				&& map[cur.first][cur.second + 1] != 'X'
				&& waterMap[cur.first][cur.second + 1] > hogMap[cur.first][cur.second] + 1)
			{
				hogMap[cur.first][cur.second + 1] = hogMap[cur.first][cur.second] + 1;
				hogs.push(make_pair(cur.first, cur.second + 1));
			}
		}
	}
	

	if (hogMap[D.first][D.second] < 100000)
		cout << hogMap[D.first][D.second];
	else cout << "KAKTUS";
}