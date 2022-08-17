/* ���� 17831�� ���� �¹��̳�
*
* Input: �Ǹſ��� �� (2 <= N <= 200,000) - �Ǹſ����� 1~N���� ��ȣ�� �Ű�����, �¹��̴� �׻� 1��
*		 2�� �Ǹſ����� N�� �Ǹſ��� ���
*		 i�� �Ǹſ��� �Ƿ��� ��Ÿ���� ���� A_i(0 <= A_i <= 100)
*
* Output: ��� ���丵 ���迡�� �߻��ϴ� �ó����� ���� �ִ밪�� ���� ū ����� �ó����� ��
*		  ���-�λ�� ���迡�� ���丵 ���谡 ������ �� �ִ�.
*		  ���丵 ���谡 �ξ��� �Ǹſ��� �ٸ� �Ǹſ��� ���丵 ���谡 �� �� ����.
*		  �ó��� ���� ���丵 ���谡 �ξ��� �Ǹſ������� �Ƿ��� ���� ���̴�.
* 
* DP������, Subtree�� ��Ʈ�� �ڽ��� �ڽİ� ���丵 �������� (��, �ڽ��� �θ�� ���丵 ���谡 �� �� ������) �� �ݴ������� ����ϸ� �ȴ�.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define MAX 200000

int skill[MAX + 1]{ 0 };
int par[MAX + 1];
vector<int> children[MAX + 1];
vector<bool> flag[MAX + 1];
int TF[MAX + 1][2]{ 0 };	// [i][0]�� �ڽ��� �ڽ��� �ڽİ� ���丵�� ��, [i][1]�� �ڽ��� �ڽİ� ���丵�� �ƴ� ��

int main()
{
	// �Ǹſ� �� �Է�
	int n;
	cin >> n;

	// ���(�θ� ���) �Է�
	for (int i = 2; i <= n; i++)
	{
		cin >> par[i];
		children[par[i]].push_back(i);
		flag[par[i]].push_back(false);
	}

	// �ɷ� �Է�
	for (int i = 1; i <= n; i++)
		cin >> skill[i];

	queue<int> BFS;
	stack<int> rev;

	BFS.push(1);
	rev.push(1);
	while (rev.size() < n)
	{
		int cur = BFS.front();
		BFS.pop();
		for (int i = 0; i < children[cur].size(); i++)
		{
			BFS.push(children[cur][i]);
			rev.push(children[cur][i]);
		}
	}

	while (!rev.empty())
	{
		int cur = rev.top();
		rev.pop();

		if (children[cur].empty())
		{
			TF[cur][0] = 0;
			TF[cur][1] = 0;
		}
		else
		{
			// ���� ���� �ڽĵ��̶� ���丵 �� �� �� - ��, �ڽĵ��� �ڽŵ��� ����Ʈ���� �ִ� ���� ����
			int maxOfChildren = 0;
			for (int i = 0; i < children[cur].size(); i++)
			{
				// �ڽĳ��� �ڱ� �ڽ��̶� ����� ��찡 �� Ŭ ��
				if (TF[children[cur][i]][0] > TF[children[cur][i]][1])
				{
					maxOfChildren += TF[children[cur][i]][0];
					flag[cur][i] = false;
				}
				// �ڽĳ��� �ڱ� �ڽ��̶� ���� �� �� ��찡 �� Ŭ ��
				else
				{
					maxOfChildren += TF[children[cur][i]][1];
					flag[cur][i] = true;
				}
			}
			TF[cur][1] = maxOfChildren;

			// �ڽ� �� �ϳ��� ����Ǵ� ���
			for (int i = 0; i < children[cur].size(); i++)
			{
				int curValue = 0;
				// cur�� i��° �ڽ��� ���丵�� �� ����.
				if (flag[cur][i])
				{
					curValue = maxOfChildren + skill[cur] * skill[children[cur][i]];
				}
				// cur�� i��° �ڽ��� ���丵 �� �� ���� => �ڽ��� �ڱ� �ڽ��̶� ���丵�� �� ����� cur�� ���丵
				else
				{
					curValue = maxOfChildren - TF[children[cur][i]][0] + TF[children[cur][i]][1] + skill[cur] * skill[children[cur][i]];
				}

				if (TF[cur][0] < curValue)
					TF[cur][0] = curValue;
			}	
		}
	}

	cout << (TF[1][0] > TF[1][1] ? TF[1][0] : TF[1][1]);

	return 0;
}