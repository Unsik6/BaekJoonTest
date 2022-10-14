/* ���� 7469 k��° ��
*
* Input: �迭�� ũ�� n�� ���� ���� Ƚ�� m (1 <= n <= 100,000, 1 <= m <= 5,000)
*		 arr[i] (0 <= i < n, |arr[i]| < 1e9)
*		 ������ ����� ���� i, j, k (1<=i<=j<=n, 1<=k<=j-i+1)

* Output: �� ������ ���ϰ�: arr[i..j]�� �������� ��, k��° ��
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N_MAX 100000

// input
int N, M;
int arr[N_MAX];

// Merge Sort Tree
// ��忡 ���ĵ� ������ ���Ƿ� vector�� �迭�� ���
// ��� ������ ������ ����� ������ 2^(ceil(logn)+1)-1������
// ���� �����ϰ� 4*N���� �Ѵٰ� �� (���׸�Ʈ Ʈ���� ����)
vector<int> tree[N_MAX * 4];

// Merge Sort Tree �����
void construct_Merge_Sort_Tree(int _node, int _left, int _right)
{
	// base case
	if (_left == _right)
	{
		tree[_node].push_back(arr[_left]);
	}
	else
	{
		// ���� ������ ������ ������ ���� ����Ʈ�� ����
		int mid = (_left + _right) / 2;
		construct_Merge_Sort_Tree(_node * 2, _left, mid);
		construct_Merge_Sort_Tree(_node * 2 + 1, mid + 1, _right);

		// ���� ��带 ä���� �ϹǷ� ������ �����α�
		tree[_node].resize(tree[_node * 2].size() + tree[_node * 2 + 1].size());

		// algorithm ����� �ִ� merge �Լ�
		// merge(first1, last1, first2, last2, output)
		// �� ���ڴ� Iterator�̸�, �� first, last�� ��ĥ �� ������ ���� Iter�̴�. => [first#, last#)
		// outputIterator�� ���ļ� ������ �ڷᱸ���� �� �� Iterator
		merge(tree[_node * 2].begin(), tree[_node * 2].end(),
			tree[_node * 2 + 1].begin(), tree[_node * 2 + 1].end(), tree[_node].begin());
	}
}


// Ǫ�� ���
// 
// ������ ���� ���Ͽ�Merge Sort Tree�� ��ȸ�ϸ鼭
// [i..j]�� �������� ��� ��� �����鿡�� ���Ͽ� �� ���� �󸶳� ū�� ����.
// 
// ���� ������ ���� ������ k�� �ٸ��� �̺� Ž������ ������ ���� ã�ư���.
// (������ ���� ������ ���ؿ� �ٸ��� ������ ������ k�� �޶�����.)
// 
// _node: ���� Ž�� ���� ���
// _left, _right: �� ����� ����
int query(int _node, int _left, int _right, int _i, int _j, int _mid)
{
	if (_j < _left || _i > _right)	// ���� �ʰ� (������ ����)
		return 0;

	// ã���� �ϴ� ���� �ȿ� �ִ� ����
	if (_i <= _left && _right <= _j)
	{
		return upper_bound(tree[_node].begin(), tree[_node].end(), _mid) - tree[_node].begin();
	}
	
	// ������ ã���� �ϴ� ������ �߶�� �� ��
	int mid_of_Interval = (_left + _right) / 2;
	int leftSide = query(_node * 2, _left, mid_of_Interval, _i, _j, _mid);
	int rightSide = query(_node * 2 + 1, mid_of_Interval + 1, _right, _i, _j, _mid);

	return leftSide + rightSide;
}

int main()
{
	cin >> N >> M;
	for (int n = 0; n < N; n++)
		cin >> arr[n];

	construct_Merge_Sort_Tree(1, 0, N - 1);

	int i, j, k;
	for (int m = 0; m < M; m++)
	{
		cin >> i >> j >> k;
		
		// ������ �� ���� (�Է°��� ����)
		int left = -1e9, right = 1e9;
		while (left <= right)
		{
			int mid = (left + right) / 2;	// �־ ������ ��
			
			if (query(1, 0, N - 1, i - 1, j - 1, mid) < k)	// ������ ���� �� �۴�.
				left = mid + 1;
			else // ������ ���� ã���� �ϴ� ������ ũ��.
				right = mid - 1;
		}

		cout << left << '\n';
	}
	return 0;
}
