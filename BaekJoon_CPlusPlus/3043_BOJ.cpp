/* ���� 3043�� �峭�� ��ũ
*
* Input: ��ũ�� ���� (5 <= N <= 500)
*		 ��ũ�� ��ġ N�� R, C (1 <= R, C <= N)

* Output: ��ũ�� �ڽ��� ��ġ�� R�� C�� ��� ĭ�� ��ȣ�Ѵ�.
*		  ��� ĭ�� ��ȣ�ϰ� �� �� �ֵ��� ��ũ�� ��ġ�Ϸ� �Ѵ�.
*		  1) ���� ���� �����̴� Ƚ��
*		  2) ��ũ �����̴� �����: (��ũ ��ȣ) (L, R, U, D)
*
* �� ���� ������ �߿����� �ʴ�. �� ���� ���� ���Ⱑ �������� �ľ��Ѵ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, char>> result;

//���� ����
bool cmp(const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b)
{
    if (a.second.first < b.second.first)
        return true;
    else if (a.second.first == b.second.first)
        return a.second.second < b.second.second;
    else
        return false;
}

void upDown(vector<pair<int, pair<int, int>>>& v)
{
    vector<int> up, down;

    //i �������� ���� ���� �Ʒ��� ���� ����
    for (int i = 1; i <= N;
        i++)
    {
        if (v[i - 1].second.first > i)
            up.push_back(i);
        if (v[i - 1].second.first < i)
            down.push_back(i);
    }

    for (int i = 0; i <
        up.size(); i++)
        for (int y = up[i]; y < v[up[i] - 1].second.first; y++)
            result.push_back(make_pair(v[up[i] - 1].first, 'U'));
    //�Ʒ��� ���� ��ũ�� �ڿ������� �����δ�
    reverse(down.begin(),
        down.end());
    for (int i = 0; i <
        down.size(); i++)
        for (int y = v[down[i] - 1].second.first; y < down[i]; y++)
            result.push_back(make_pair(v[down[i] - 1].first, 'D'));
}

void leftRight(vector<pair<int, pair<int, int>>>& v)
{
    vector<int> left, right;

    //i �������� �������� ���� ���������� ���� ����
    for (int i = 1; i <= N;
        i++)
    {
        if (v[i - 1].second.first > i)
            left.push_back(i);
        if (v[i - 1].second.first < i)
            right.push_back(i);
    }

    for (int i = 0; i <
        left.size(); i++)
        for (int x = left[i]; x < v[left[i] - 1].second.first; x++)
            result.push_back(make_pair(v[left[i] - 1].first, 'L'));
    //���������� ���� ��ũ�� ���������� �����δ�
    reverse(right.begin(),
        right.end());
    for (int i = 0; i <
        right.size(); i++)
        for (int x = v[right[i] - 1].second.first; x < right[i]; x++)
            result.push_back(make_pair(v[right[i] - 1].first, 'R'));
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin �ӵ� ��� ����

    cin >> N;
    vector < pair<int, pair<int, int>>> yFirst;
    //���� ����
    vector < pair<int, pair<int, int>>> xFirst;
    //���� ����

    for (int i = 1; i <= N;
        i++)
    {
        int y, x;
        cin
            >> y >> x;

        yFirst.push_back(make_pair(i,
            make_pair(y, x)));
        xFirst.push_back(make_pair(i,
            make_pair(x, y)));
    }

    sort(yFirst.begin(),
        yFirst.end(), cmp);
    upDown(yFirst);
    sort(xFirst.begin(),
        xFirst.end(), cmp);
    leftRight(xFirst);

    //endl �ð��ʰ�
    cout << result.size() << "\n";
    for (int i = 0; i <
        result.size(); i++)
        cout
        << result[i].first << " " << result[i].second << "\n";

    return 0;
}


//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//#define pos pair<int, int>
//struct tank { int id = 0; pos position; };
//
//int N;
//int map[501][501]{ 0 };
//vector<tank> rTanks;
//vector<tank> cTanks;
//
//#define output pair<int, char>		// <id, dir>
//queue<output> outputs;
//
//bool compR(tank _a, tank _b) { return _a.position.first < _b.position.first; }
//bool compC(tank _a, tank _b) { return _a.position.second < _b.position.second; }
//
//void updown(vector<tank>& _tanks)
//{
//	vector<int> up, down;
//	for (int i = 0; i < _tanks.size(); i++)
//	{
//		// up
//		if (_tanks[i].position.first > i + 1)
//			up.push_back(i);
//		else down.push_back(i);
//
//		// UP move
//		for(int i = 0; i < up.size(); i++)
//			for(int d = up[i]; d < i + 1;)
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		int r, c;
//		cin >> r >> c;
//		pos tmpPos{ r, c };
//		tank tmp{ i, tmpPos };
//		rTanks.push_back(tmp);
//		cTanks.push_back(tmp);
//		map[r][c] = i;
//	}
//
//	sort(rTanks.begin(), rTanks.end(), compR);
//	sort(cTanks.begin(), cTanks.end(), compC);
//	
//
//	//// ���� ��
//	//for (int i = 0; i < N; i++)
//	//{
//	//	cout << dstTanks[i].id << " (" << dstTanks[i].position.first << ", " << dstTanks[i].position.second << ")\n";
//	//}
//	////
//
//	
//	return 0;
//}
