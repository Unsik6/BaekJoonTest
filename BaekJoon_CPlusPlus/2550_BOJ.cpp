/* ���� 2550�� ����
*
* Input: ����ġ�� ���� ���� �� (1 <= N <= 10,000)
*		 N�� ����ġ�� ��������� ��ȣ x_i (1 <= x_i <= 10,000, x_i != x_j)
*		 N�� ������ ��������� ��ȣ x_i (1 <= x_i <= 10,000, x_i != x_j)

* Output: ����ġ ��ȣ�� ���� ��ȣ�� ���ٸ� ������ ����Ǿ� ������ �ǹ��Ѵ�.
*		  ������ �����ϴ� �� ����ġ�� ���ÿ� �۵���ų �� ����.
*		  
*		  ������ ���� ���� ������ ��쿡 ���Ͽ�,
*		  ���� ������ ����,
*		  ���� �����鿡 �����ϴ� ����ġ�� ��ȣ�� ������������ ����Ͻÿ�.
*
* LIS �����̴�.
* ����ġ���� �۵������� ��, ��� ������ �������� �ʴ� ���� ����ġ�� ��ġ ����(��������)�� ���� ������ ��ġ�� ���������� ����̴�.
* �׷��Ƿ� ������ ��ġ ������ ����ġ�� ��ġ�� �����ϰ�, �׿� ���� LIS�� ���Ѵ�.
* ������ ������ �����ϳ�, LIS�� �籸���ؾ� �Ѵٴ� ���� �ٸ���.
*/

#include <iostream>
#include <algorithm>

using namespace std;


int switch_pos[10001];
int bulb_no[10000];
int bulb_idx[10000];
int lis_len[10000];
int pre[10000];
bool turn_on[10001]{ false };

int main()
{
	// input
	int N;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		switch_pos[num] = i;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		bulb_idx[i] = switch_pos[num];
		bulb_no[i] = num;
	}

	int max_idx = 0;
	int max_len = 0;
	for (int i = 0; i < N; i++)
	{
		lis_len[i] = 1;
		pre[i] = i;
		for (int j = 0; j < i; j++)
		{
			if (bulb_idx[j] < bulb_idx[i])
			{
				// �� �� ���
				if (lis_len[i] < lis_len[j] + 1)
				{
					lis_len[i] = lis_len[j] + 1;
					pre[i] = j;
				}
			}
		}
		if (max_len < lis_len[i])
		{
			max_len = lis_len[i];
			max_idx = i;
		}
	}

	// backtrack the LIS
	int cur = max_idx;
	turn_on[bulb_no[max_idx]] = true;
	while (cur != pre[cur])
	{
		cur = pre[cur];
		turn_on[bulb_no[cur]] = true;
	}

	// output
	cout << max_len << '\n';
	for (int i = 1; i <= N; i++)
	{
		if (turn_on[i])
			cout << i << ' ';
	}
}