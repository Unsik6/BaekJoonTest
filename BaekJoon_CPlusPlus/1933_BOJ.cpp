/* ���� 1933 ��ī�̶���
*
* Input: �ǹ��� �� N (1 <= N <= 100,000)
*		 �ǹ��� ���� X��ǥ L, ���� H, ������ X ��ǥ R (1 <= L < R <= 1,000,000,000, 1 <= H <= 1,000,000,000)

* Output: ���̰� ���ϴ� ������ ���ؼ� �� ������ X ��ǥ�� �� ���������� ����
*/

#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;


// input
int N;
int building_L, building_R, building_H;

// �ǹ�
map<int, int> field;	// key: x��ǥ; value: union_find set�� root
pair<int, pair<int, int>> buildings[100000];	// {par, {H, R}}

void insertBuilding(int _idx, int _l, int _h, int _r)
{
	if (field.find(_l) == field.end())
	{
		field[_l] = _idx;
		buildings[_idx] = { _idx, {_h, _r} };
	}
	else
	{
		buildings[_idx] = { field[_l], {_h, _r} };
		field[_l] = _idx;
	}
}

// solution��
struct comp
{
	bool operator()(int _a, int _b)
	{
		return buildings[_a].second.first < buildings[_b].second.first;
	}
};
priority_queue<int, vector<int>, comp> pq;


int main()
{
	// �Է� �ޱ�
	cin >> N;

	for (int n = 0; n < N; n++)
	{
		cin >> building_L >> building_H >> building_R;
		insertBuilding(n, building_L, building_H, building_R);
	}


	for (map<int, int>::iterator iter = field.begin(); iter != field.end(); iter++)
	{
		// down
		bool down = false;
		int preRight = (pq.empty() ? -1 : buildings[pq.top()].second.second);
		int preH = (pq.empty() ? 0 : buildings[pq.top()].second.first);
		while (!pq.empty())
		{
			if (buildings[pq.top()].second.second >= iter->first)
				break;
			
			pq.pop();
			
			// ť�� ����ִٸ� �ٴ����� ���� ���� ��
			if (pq.empty())
				cout << preRight << ' ' << 0 << ' ';
			else if (buildings[pq.top()].second.second > preRight)	// ���� ž�� {���� �ִ� ���� �ǹ�}�� ������ ������ �����ʿ��� ������ ��ܽ�
			{
				if (buildings[pq.top()].second.first < preH)		// ��ܽ��� �ƴ϶� �ǹ� ���̰� ������ ���� ������ ���� ����ó��
				{
					cout << preRight << ' ' << buildings[pq.top()].second.first << ' ';
					if (!down) down = true;
				}
				preRight = buildings[pq.top()].second.second;
				preH = buildings[pq.top()].second.first;
			}
		}

		bool up = false;
		int preTopH = (pq.empty() ? 0 : buildings[pq.top()].second.first);
		int idx = iter->second;
		while (true)
		{
			pq.push(idx);
			if (buildings[idx].second.first > preTopH)
				up = true;

			if (idx == buildings[idx].first)
				break;
			else
				idx = buildings[idx].first;
		}

		if (up)
		{
			cout << iter->first << ' ' << buildings[pq.top()].second.first << ' ';
		}
	}

	// ������ �����ɱ⸦ ���� down
	// down
	int preRight = (pq.empty() ? -1 : buildings[pq.top()].second.second);
	int preH = (pq.empty() ? 0 : buildings[pq.top()].second.first);
	while (!pq.empty())
	{
		pq.pop();

		if (pq.empty())
			cout << preRight << ' ' << 0 << ' ';
		else if (buildings[pq.top()].second.second > preRight)
		{
			if(buildings[pq.top()].second.first < preH)
				cout << preRight << ' ' << buildings[pq.top()].second.first << ' ';
			preRight = buildings[pq.top()].second.second;
			preH = buildings[pq.top()].second.first;
		}
	}

	return 0;
}