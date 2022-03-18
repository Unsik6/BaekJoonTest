// ���� 1202�� ���� ����

// input: ������ ���� N, ������ ���� K (1 <= N, K <= 300,000)
//		  �� ������ ���� Mi, ��ġ Vi (0 <= Mi, Vi <= 1,000,000)
//		  ���濡 ���� �� �ִ� �ִ� ���� Ci (1 <= Ci <= 100,000,000)

// condition: ������ ���濡�� �ִ� �� ���� ������ ���� �� �ִ�.

// output: ��ģ �������� ��ġ�� ������ �ִ밡 �� ���� ��ġ�� ����

// 1. ������ ���Ը� ������������ �����Ѵ�.
// 2. ���Ը� �߽����� ������������ �����Ѵ�.
// 3. �� ���濡 ���Ͽ� 2������ ���ĵ� �� �� ���� �� �ִ� ���� �ռ� ������ �ִ´�.

// �̶� 3���� �ܼ��� ���߹ݺ������� �� ���濡 ���Ͽ� �����ִ� ��� ������ ���ϸ� �ð��ʰ��� �߻��Ѵ�.
// �켱����ť�� ����Ѵ�.
// �� ���� ���Կ� ���Ͽ� ���� �� �ִ� �������� ��ġ�� �켱����ť�� �ִ´�.
// �׸��� ���� 1���� �Ҹ��Ͽ� �켱����ť���� pop�� �Ѵ�.
// �� ����� ������ ���� ������ �����Ѵ�.
// ��ġ�� ���� ���� ���� �� ������ �� �ִ� ������ ���� �Ҹ��Ѵ�.
// ������ ������ ���������̹Ƿ� �켱����ť�� �ִ� �������� ������ �� �ִ� �������̴�.

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define jewel pair<int, int>



bool compareJewel(jewel _a, jewel _b)
{
	if (_a.first != _b.first)
	{
		return (_a.first < _b.first);
	}
	else
	{
		return (_a.second > _b.second);
	}
}

long long maxValue(vector<jewel>& _jewels, int _n, vector<int>& _bags, int _k)
{
	
	long long totalValue = 0;
	priority_queue<int> pq;
	int jewelIdx = 0;
	for (int k = 0; k < _k; k++)
	{
		while (jewelIdx < _n && _jewels[jewelIdx].first <= _bags[k])
		{
			pq.push(_jewels[jewelIdx].second);
			jewelIdx++;
		}
		if (!pq.empty())
		{
			totalValue += (long long)pq.top();
			pq.pop();
		}
	}

	return totalValue;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<jewel> jewels;
	for (int i = 0; i < N; i++)
	{
		int M, V;
		cin >> M >> V;
		jewels.push_back(make_pair(M, V));
	}
	vector<int> bags;
	for (int k = 0; k < K; k++)
	{
		int bag;
		cin >> bag;
		bags.push_back(bag);
	}
	
	sort(jewels.begin(), jewels.end(), compareJewel);
	sort(bags.begin(), bags.end());

	cout << maxValue(jewels, N, bags, K);
	return 0;
}