/* ���� 2516 ������
*
*Input: ������ �� N (3 <= N <= 100,000)
*		N���� �ٿ� �Ӽ����� ������ �� M, �Ӽ����� ������ ��ȣ M�� (0 <= M <= N-1)

* Output: 2�������� �����̵��� ��������.
*		  1) �� �����̿� ���Ͽ� ���� �������� �Ӽ������� �����̴� �ִ� 1�������� �Ѵ�.
*		  2) ��� �����̸� �� �������� ������ �� �ȴ�.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// input
int N;

// graph
// Adjacency Matrix ��� M in O(N^2)��
// �ٵ� 10��*10���ϸ� bit ������ �����Ѵٰ� �ص� 1250MB�� ����
// �� ������ ���� ���ٰ� �����ϱ� �׷��Ա��� ������ ���� �����״� Adjacency List�� �غ���.
// ������ ������ �ΰ��� �������� �����ٰ� ���� ��, �� ũ�⸦ ���� a, b��� �غ���.
// �� ���� �ȿ��� ������ �� �ִ� ������ �ִ� ������ floor(a/2) �Ǵ� floor(b/2)�̴�.
// �׸��� �� ���� ���̿� ������ �� �ִ� ������ ������ ab�̴�.
// b = N - a�̹Ƿ� a(N-a)�� �ȴ�.
// �׷��Ƿ� �� ������ ���� a(N-a) + N/2��� �� �� �ִ�.
// a�� Ŀ������ N-a�� Ŀ���Ƿ� �־��� ��쿡�� O(N^2)������ N^2/4 + N/2�̴�.

vector<int> graph[100001];
int monkeys[100001];
bool cageOfMonkeys[100001]{ false };	// 0 �Ǵ� 1

bool comp(int _a, int _b)
{
	if (graph[_a].size() != graph[_b].size())
		return graph[_a].size() > graph[_b].size();
	return _a < _b;
}

void input()
{
	cin >> N;
	for (int monIdx = 1; monIdx <= N; monIdx++)
	{
		int M, devil;
		cin >> M;
		for (int m = 0; m < M; m++)
		{
			cin >> devil;
			graph[monIdx].push_back(devil);
		}
	}
}

void solution()
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 1; i <= N; i++)
		{
			int cnt = 0;
			for (int j = 0; j < graph[i].size(); j++)
				cnt += (cageOfMonkeys[i] == cageOfMonkeys[graph[i][j]]);
			if (cnt > 1)
			{
				cageOfMonkeys[i] = !cageOfMonkeys[i];
				flag = true;
			}
		}
	}
}

void output()
{
	vector<int> a, b;
	for (int i = 1; i <= N; i++)
		cageOfMonkeys[i] ? a.push_back(i) : b.push_back(i);

	// a�� ������� ��� (true �� ������)
	if (a.empty())
	{
		a.push_back(b.back());
		b.pop_back();
	}

	cout << a.size() << ' ';
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << '\n';

	cout << b.size() << ' ';
	for (int i = 0; i < b.size(); i++)
		cout << b[i] << ' ';
}


int main()
{
	input();
	solution();
	output();
	return 0;
}