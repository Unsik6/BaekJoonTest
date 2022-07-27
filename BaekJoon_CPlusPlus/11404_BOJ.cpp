/* ���� 11404�� �÷��̵�
*
* Input: 	������ ���� N (2 <= N <= 100)
*			���� �뼱�� ���� M (1<= M <= 100,000)
*		 <����° �� ... >
*			�� �ٿ� ���� �뼱�� ���� A, B, C (1 <= A, B <= N, A != B, 1 <= C <= 10,000)
*
* Output: i��° �ٿ� ����ϴ� j��° ���ڴ� ���� i���� j�� ���� �ּҺ��
*		  ���� ���� ��� 0
*
* Point:
*		�÷��̵�-�ͼ�
*/

#include <iostream>
using namespace std;

#define INF 2000000000

int mat[101][101];

int main()
{
	int N, M, src, dst, cost;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			mat[i][j] = INF;

		mat[i][i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> src >> dst >> cost;
		if(mat[src][dst] > cost) mat[src][dst] = cost;
	}

	for (int way = 1; way <= N; way++)
	{
		for (int s = 1; s <= N; s++)
		{
			if (s == way) continue;
			for (int d = 1; d <= N; d++)
			{
				if (d == way || d == s || mat[s][way] == INF || mat[way][d] == INF) continue;
				
				int newD = mat[s][way] + mat[way][d];
				if (newD < mat[s][d])
					mat[s][d] = newD;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (mat[i][j] == INF) cout << 0 << ' ';
			else cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
}