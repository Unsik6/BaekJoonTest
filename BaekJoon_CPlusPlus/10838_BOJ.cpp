/* ���� 10838 Ʈ��
*
* Input: ����� �� N ( 1 <= N <= 10^5)
*		 ������ ���� K ( 1 <= K <= 3*10^5)
*		 ���� r = 1(paint) a, b, c (0 <= a, b <= N-1, 0 <= c <=10^9)
*			  r = 2(move) a, b ( 1<= a <= N-1, 0 <= b <= N-1)
*			  r = 3(count) a, b ( 0 <= a, b <= N -1)
		
		����:
			paint(a, b, c): a�� ���� b�� ��带 �մ� �ִ� ��θ� ã�� ��, ��� �� �ִ� ��� ������ ���� c�� ĥ�Ѵ�. 
			move(a, b): a�� ����� �θ� ��带 b�� ���� �ٲ۴�. ��, b�� ���� a�� ��带 ��Ʈ�� �ϴ� ��Ʈ��(subtree)�� ������ �ʴ´�.
						�θ� ��带 �ٲٱ� �� a�� ����� �θ� ��带 p�� �� ��, ���ο� ���� (a,b)�� ������ ���� (a,p)�� ������ ���´�. 
			count(a, b): a�� ���� b�� ��带 �մ� �ִܰ�θ� ã�� ��, �� ��� ���̿� �ִ� ������ ĥ���� ���� �ٸ� ������ ������ ����Ѵ�. 
		
		����:
			�ʱ⿡ ��� ���� 0�� �ڽ��̴�. 0�� ��Ʈ�̴�.
			paint�� count ����� a�� ���� b�� ��� ������ �ִܰ���� ���̴� �׻� 1,000�̴�.

* Output: �Է¿��� �־��� count ���� ������ ���� ������� ����� �� �ٿ� ����Ѵ�.
*/

// �ִ� ��ΰ� �ִ� 1,000�̹Ƿ� �ִ� ��δ� LCA�� �б�� �Ѵ�.
// ��, ������ Ʈ���� �ƴϹǷ� depth ������ �����ϴ� ���� �ð��� �� ���� �ɸ���.
// �׷��Ƿ� ��Ʈ������ ��θ� check�ϴ� �������� �����Ѵ�.

#include <iostream>
#include <utility>
#include <set>

using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// input
int nodeNum, operNum, operId, node1, node2, color;

// tree
int arrParent[100'000]{ 0 };
int arrColor[100'000]{ 0 };

// methods
// �ִ� ��� üũ�� �뵵�� �迭�� �� ����� ���̵�
int checkIdx = 1;
int node1Check[100'000]{ 0 };
int node2Check[100'000]{ 0 };

int findLCA(int _node1, int _node2)
{
	if (_node1 == _node2)
		return _node1;

	int curNode1 = _node1, curNode2 = _node2, lcaIdx = -1;
	node1Check[_node1] = node2Check[_node2] = checkIdx;

	for (int i = 0; i < 1000; i++)
	{
		// �ö󰡴� �߿� ��Ʈ�� �Ѿ�� ���̻� �� �ö�
		if (curNode1 >= 0)
		{
			curNode1 = arrParent[curNode1];
		}
		if (curNode2 >= 0)
		{
			curNode2 = arrParent[curNode2];
		}

		// �ٸ� ��ο��� �̹� üũ�� ���� ������ LCA�̴�.
		if (curNode1 >= 0)
		{
			if (node2Check[curNode1] == checkIdx)
			{
				lcaIdx = curNode1;
				break;
			}
			node1Check[curNode1] = checkIdx;
		}
		if (curNode2 >= 0)
		{
			if (node1Check[curNode2] == checkIdx)
			{
				lcaIdx = curNode2;
				break;
			}
			node2Check[curNode2] = checkIdx;
		}	 
	}

	return lcaIdx;
}

void paint(int _node1, int _node2, int _color)
{
	int lcaIdx = findLCA(_node1, _node2);
	
	// ��� �� �ִ� ����̹Ƿ� LCA�� ���� ĥ�ϸ� �� �ȴ�.
	int curNode = _node1;
	while (curNode != lcaIdx)
	{
		arrColor[curNode] = _color;
		curNode = arrParent[curNode];
	}
	curNode = _node2;
	while (curNode != lcaIdx)
	{
		arrColor[curNode] = _color;
		curNode = arrParent[curNode];
	}
}

void move(int _node1, int _node2)
{
	arrParent[_node1] = _node2;
}

int count(int _node1, int _node2)
{
	int lcaIdx = findLCA(_node1, _node2);
	set<int> stColors;

	// ��� �� �ִ� ����̹Ƿ� LCA�� ���� ���� �ȵȴ�.
	int curNode = _node1;
	while (curNode != lcaIdx)
	{
		stColors.insert(arrColor[curNode]);
		curNode = arrParent[curNode];
	}
	curNode = _node2;
	while (curNode != lcaIdx)
	{
		stColors.insert(arrColor[curNode]);
		curNode = arrParent[curNode];
	}

	return stColors.size();
}

int main()
{
	fast_io

	// input & set a tree
	cin >> nodeNum >> operNum;
	arrParent[0] = -1;


	// operate
	for (int o = 0; o < operNum; o++)
	{
		cin >> operId >> node1 >> node2;
		
		switch (operId) {
		case 1:
			cin >> color;
			paint(node1, node2, color);
			break;
		case 2:
			move(node1, node2);
			break;
		case 3:
			cout << count(node1, node2) << '\n';
			break;
		}

		checkIdx++;
	}

	return 0;
}