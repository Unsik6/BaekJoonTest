/* ���� 11437�� LCA
*
* Input: ����� ���� N ( 2<= N <= 50,000 )
*		 1���� ��Ʈ�� Ʈ�� �Է� -> Ʈ�� ����� �� ��� �Է�
*		 �� ����� ��(������ ��) M ( 1 <= M <= 10,000 )
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
using namespace std;

#define INT_VEC vector<int>


// Information of tree
int depths[50001]{ 0 };
int parent[50001]{ 0 };

INT_VEC graph[50001];
int lcas[10000];

// input
int n, m;

int main()
{
	cin >> n;
	
	// ��� ���� ���� �Է� �ޱ�
	// BFS �̿�
	for (int i = 0; i < n - 1; i++)
	{
		int v, w;
		cin >> v >> w;
		graph[v].push_back(w);
		graph[w].push_back(v);
	}

	queue<int> bfsQ;
	bfsQ.push(1);
	while (!bfsQ.empty())
	{
		int cur = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			// �̹� �湮�� ���(��� ��ȣ 1 �Ǵ� depth�� ������)�� �湮 �� ��
			if (graph[cur][i] != 1 && parent[graph[cur][i]] == 0)
			{
				bfsQ.push(graph[cur][i]);
				depths[graph[cur][i]] = depths[cur] + 1;
				parent[graph[cur][i]] = cur;
			}
		}
	}
	
	// ���� ����
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int v, w;
		cin >> v >> w;
		// v�� depth�� �� ���� ����
		if (depths[v] > depths[w]) v ^= w ^= v ^= w;
		
		// depths ���߱�
		while(depths[w] != depths[v])
			w = parent[w];

		// �Ž��� �ö󰡱�
		// ���� v�� w�� �θ� ���� ������ �ö� ���
		// �Ž��� �ö󰡱Ⱑ ������ parent[v]�� lca��� �ϸ� �� �ȴ�.
		//  v �Ǵ� w ��� ��ü�� ���� ������ �Ǵ� case�� ��츦 �������� �Ѵ�.
		while (w !=v)
		{
			w = parent[w];
			v = parent[v];
		}

		lcas[i] = v;
	}
	
	for (int i = 0; i < m; i++)
		cout << lcas[i] << '\n';

	return 0;
}
