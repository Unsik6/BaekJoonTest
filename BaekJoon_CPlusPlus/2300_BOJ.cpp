/* ���� 2300 ������
*
*Input: �ǹ��� ���� N ( 1 <= N <= 10,000)
*		�� �ٸ��� �ǹ��� ��ǥ x, y (|x|,|y| <= 1,000,000)

		��� �ǹ��� y��ǥ�� 0�� �� �� ����.
		�������� x�� ���� �Ǽ��Ǹ�, y��ǥ�� 0���� �����̴�.
		�������� �߽����� ���簢�� ������ ��Ź����̴�.
		�������� �ּ� ������ �ƴ� ��Ź����� �� ���� ������ �ּҰ� �Ǵ� ���� ���ؾ� �Ѵ�.

* Output: ��Ź����� �� ���� ������ �ּҰ�
*/

// DP ������
// pos_a�� a��° �ǹ��̶�� ���� ��
// T(pos_a,pos_b)�� a��° �ǹ����� b��° �ǹ������� ���� �����ض�� ����.
// T(pos_1,pos_N)=min(T(pos_1, pos_k)+T(pos_{k+1},pos_N))
// �̴� �� ��� ����� ���� Ž���ϴ� �Ͱ� ����.

#include<iostream>
#include<algorithm>
using namespace std;

#define INF 9e9	// ��� �ƹ��� Ŀ���� 2�鸸 �������̴�.

// input
int N;
pair<int, int> buildings[10001];

// DP
int dp[10001]{ 0 };	// dp[0]�� base case�� �ǹ� 0���̹Ƿ� 0�̴�.

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> buildings[i].first >> buildings[i].second;
	
	// ������ ���� �� �տ� ��ĭ�� �������� �ʰ� ����
	sort(buildings + 1, buildings + N + 1);

	// DP
	// �տ������� ��ȸ�Ѵ�.
	for (int i = 1; i <= N; i++)
	{
		// �ϴ� �ּҰ��� ã�ƾ��ϴϱ� ����Ʈ�� INF�̴�.
		dp[i] = INF;
		int maxHeight = 0;
		for (int j = i; j >= 1; j--)
		{
			// j~i��° �ǹ����� ���´ٰ� ����.
			
			// �ϴ� �ǹ� ���� �ֽ�ȭ
			maxHeight = max(maxHeight, abs(buildings[j].second));

			// ������ ������ ��(���±��� ���� ���̽� �� ����)��
			// ������ ����� T(1, j-1)+T(j, i)�� ���Ѵ�.
			dp[i] = min(dp[i], dp[j - 1] + max(2 * maxHeight, buildings[i].first - buildings[j].first));
		}
	}
	
	// ���
	cout << dp[N];

	return 0;
}
