/* ���� 2533 ��ȸ�� ����(SNS)
*
*Input: ģ�� Ʈ���� ���� �� N (2 <= N <= 1'000'000)
*			- �� ���� ��ȣ�� 1 ~ N�̴�.
*		Ʈ���� ���� (u, v) (1 <= u, v <= N)

* Output: �� �ƴ��� ������ �� �ƴ��Ͱ� �ƴ� �������� ������.
*		  �̶�, �� �ƴ��Ͱ� �ƴ� ������ ������ ��� ������ �� �ƴ��Ϳ��� �Ѵ�.
		  ��� ������ �� �ƴ����̰ų� �� ������ �����ϴ� ��쿡 �ּ� �� �ƴ��� ����� ���� ����϶�.
*/

/*
* ������ �ô� DP �����̴�.
* Subtree ������ �� ������ �����ϸ� �ȴ�.
* (1) Node�� �� �ƴ��Ͱ� �ƴ� ���	=> ��� �ڽ� ������ �� �ƴ��Ϳ��� �Ѵ�.
* (2) Node�� �� �ƴ����� ���			=> ��� �ڽ� ������ �� �ƴ������� �ƴ��� ��� ����.
										   ��� '�ڽ� ��带 ��Ʈ�� �ϴ� ����Ʈ��'���� ���� �ּ� �� �ƴ��� ���� �����ָ� �ȴ�.
*/

#include <iostream>
#include <vector>

using namespace std;

#define TE 0	// True Earlyadopter
#define FE 1	// False Earlyadopter

// input
int N;

// graph
// |E| in O(|V|)�̹Ƿ� Adjaceny list representation�� �ո����̴�.
// ����, �޸� ������ 256MB�̰� N <= 1*10^6�̹Ƿ�,
// Adjaceny matrix�� �� ���, 1*10^6MB�� �ʿ��ؼ� �Ұ����ϴ�.
vector<int> graph[1'000'001];

// dpMat[node][case]
int dpMat[1'000'001][2]{ 0 };

// recursive solution
// Ʈ���� Ȱ���ϴ� ������ input�� ���� 2�����̴�.
// (1) {parent, child} ���·� ���� ������ �޴´�.
// (2) {node, node} ���·� ���� ������ �޴´�. 
// 1���� ���, parent�� child�� �����ϴ� �������� �ٷ� Ʈ���� ������ �� �ִ�.
// 2���� ���, graph�� �ް� ��ó���� ���� �ռ� ����� Ʈ���� �����Ѵ�.
// ������ �� ������ �θ�-�ڽ� ���谡 �߿��� ���� �ƴ϶� '����'�� �߿��ϴ�.
// �׷��Ƿ� � �������� �����ϵ� �Ȱ���.
void solution(const int _node, const int _parent)
{
	// Base case
	// ������ Ư���� ������尡 0���� ���̽��� ���� �ϴ�. (2 <= N)
	// ������尡 1����� leaf node�̴�. (1���� ������ �θ�)
	// _parent �˻絵 ���ִ� ������ ��尡 2���� ��,
	// �� if���� ��Ʈ ��嵵 �ɸ��� ������ �ֱ� �����̴�.
	if (graph[_node].size() < 2 && _parent != -1)
	{
		dpMat[_node][TE] = 1;
		// dpMat[_node][FE] = 0;	0���� �ʱ�ȭ�� ���� �ʿ� ����.
		// ���⼭ �߿��� ���� Base Case�� solution�� ������ �ƴ϶�� ���̴�.
		// ���� Ʈ���� ��尡 �Ѱ���� ������ ������ 1�̴�. ������ ���� ���� �����ϸ� 0�� �ȴ�.
		// �׷��� �� ������ 2 <= N�̱� ������ Base case�� ������ �ƴϴ��� ���� ��ü�� ������ ����ȴ�.

		return;
	}

	for (int childIdx = 0; childIdx < graph[_node].size(); childIdx++)
	{
		int childNode = graph[_node][childIdx];
		// �������� Ʈ�� ���¸� �����ϹǷ�, �θ� �ƴϸ� �ڽ��̴�.
		if (childNode != _parent)
		{
			// �ϴ� �� �ڽ� ����� �������� �Ѵ�.
			solution(childNode, _node);

			// (1) ���� �� �ƴ��Ͱ� �ƴϴ�!
			//	   ��� �ڽ��� �� �ƴ����� ��츦 �� ������.
			dpMat[_node][FE] += dpMat[childNode][TE];

			// (2) ���� �� �ƴ��ʹ�!
			//		�ڽ��� TE�� ���� FE�� ��� �߿��� ���� ���� �� ������.
			dpMat[_node][TE] += min(dpMat[childNode][TE], dpMat[childNode][FE]);
		}
	}
	
	dpMat[_node][TE]++;	// ���� �� �ƴ��ʹϱ� +1
}

int main()
{
	cin >> N;
	for (int n = 0; n < N - 1; n++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// ������ �����߰�����, ��� �����ϵ� ��� ����.
	solution(1, -1);

	cout << min(dpMat[1][TE], dpMat[1][FE]);
}