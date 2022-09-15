/* ���� 11437�� LCA
*
* Input: ����� ���� N ( 2<= N <= 100,000 )
*		 1���� ��Ʈ�� Ʈ�� �Է� -> Ʈ�� ����� �� ��� �Է�
*		 �� ����� ��(������ ��) M ( 1 <= M <= 100,000 )
*
*		 * �� Ʈ���� ������ 1~N���� �ε��̵Ǿ� ����

* Output: ���� �ֿ� ���� LCA ���
*
* ����
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

#define INT_VEC vector<int>

// Information of tree
int depths[100001]{ 0 };
int parents[100001][17];	// parents[[i][k] = i�� ����� 2^k��° �θ�
							// n�� 100,000�̹Ƿ� 2^16��° �θ������ ���� �� �ִ�.
int max_depth;

INT_VEC graph[100001];	// Ʈ���� �����ϱ� ���� �׷���

// input
int n, m;

// BFS�� Ʈ�� ���� ����
void set_tree(int _node, int _par, int _d)
{
	depths[_node] = _d;
	parents[_node][0] = _par;

	// ����� ���ϱ�
	// child�� 2^k��° ������
	// child�� 2^(k-1)��° ������ 2^(k-1)��° ����
	for (int i = 1; i <= max_depth; i++)
		parents[_node][i] = parents[parents[_node][i - 1]][i - 1];

	for (int i = 0; i < graph[_node].size(); i++)
	{
		int child = graph[_node][i];
		if (child == _par) continue;	// Ʈ������ �� ��찡 �ƴϸ� �湮�ߴ� ��带 �湮�� ���� ����.
		set_tree(child, _node, _d + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int v, w;
		cin >> v >> w;

		graph[v].push_back(w);
		graph[w].push_back(v);
	}

	max_depth = (int)floor(log2(100000));

	// BFS�� Ʈ�� ���� ����
	set_tree(1, 0, 1);

	// ���� ����
	cin >> m;
	int v, w;
	for (int t = 0; t < m; t++)
	{
		cin >> v >> w;
		
		if (v == 1 || w == 1)
		{
			cout << 1 << '\n';
			continue;
		}

		// w�� �� ū ���̸� ������ ����
		if (depths[v] > depths[w])
			v ^= w ^= v ^= w;

		// �� ����� depth ���߱�
		// ���� Ž������ �����Ѵ�. ���� �ָ� �ִ� ������� Ȯ���Ѵ�.
		if (depths[v] != depths[w])
		{
			for (int i = max_depth; i >= 0; i--)
			{
				if (depths[parents[w][i]] >= depths[v])
					w = parents[w][i];

				// w = parents[w][k]�� ������ ����
			// parents[w][k]�� 2^k��° ������ �� �ʿ䰡 ���ٴ� ���̴�.
			// parents[w][k]�� 2^k��° ������ parents[w][k+1]�� ���� �����̴�.
			}
		}

		// lca ã��
		if (v != w)
		{
			for (int i = max_depth; i >= 0; i--)
			{
				if (parents[v][i] != parents[w][i])
				{
					v = parents[v][i];
					w = parents[w][i];
				}
				// v�� w�� ����� �� LCA���� ���� �ִ� ����鵵 ��� ���� �����̴�.
				// �׷��Ƿ� depth ���߱�� �����ϰ� ����Ž������ �ö󰣴�.
			}
			// ���������� lca �ٷ� �Ʒ� ��尡 ����ȴ�.
			v = parents[v][0];
		}

		cout << v << '\n';
	}

	return 0;
}