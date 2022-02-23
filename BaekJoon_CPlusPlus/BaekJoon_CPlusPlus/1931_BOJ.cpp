// ���� 1931�� ����0

// input: 1 <= N = ȸ���� �� <= 100,000
//		  �� ȸ���� ���۽ð�, �� �ð�. 0 <= s <= f <= 2^31 - 1

// condition: �� ���� ȸ�ǽǿ� ������ �ִ��� ȸ���� ��

// activity-selection problem

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

#define PAIR pair<int, int>

bool comparer(PAIR _a, PAIR _b)
{
	// ������ �ð��� ���� ���, �����ϴ� �ð��� ������������ �������־�� �Ѵ�.
	return (_a.second < _b.second || (_a.second == _b.second && _a.first < _b.first));
}

int main()
{
	int N;
	cin >> N;
	vector<PAIR> dis;
	for (int i = 0; i < N; i++)
	{
		int s, f;
		cin >> s >> f;
		dis.push_back(make_pair(s, f));
	}
	sort(dis.begin(), dis.end(), comparer);

	int m{ 0 }, cnt{ 1 };
	for (int k = 1; k < N; k++)
	{
		if (dis[m].second <= dis[k].first)
		{
			m = k;
			cnt++;
		}
	}

	cout << cnt;
}