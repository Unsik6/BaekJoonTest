// ���� 1065�� �Ѽ�

// Input: 1<= N <= 1000
// condition: � ���� ���� X�� �� �ڸ��� ���������� �̷�ٸ� �Ѽ�
//			  1<= X <= N �� �Ѽ��� ������ ���Ͻÿ�.

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N, cnt{ 0 };
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		vector<int> v;
		int now = i;
		while (true)
		{
			v.push_back(now % 10);
			now /= 10;
			if (now == 0) break;
		}
		if (v.size() < 3)
		{
			cnt++;
			continue;
		}
		int d = v[1] - v[0];
		bool isEnd = true;
		for (int f = 0; f < v.size() - 1; f++)
		{
			int next = f + 1;
			if (v[next] - v[f] != d)
			{
				isEnd = false;
				break;
			}
		}

		if (isEnd) cnt++;
	}
	cout << cnt;
}