/* ���� 1708�� ���� ����
*
* Input: ���� ���� N (3 <= N <= 100,000)
*		 N���� �ٿ� x��ǥ, y��ǥ (|x|,|y| <= 40,000)
*

* Output: ���� ������ �̷�� ���� ������ ���
*
* Convex hull
* ��ǥ���� �˰���: Graham's Scan
* 1) Preprocessing (nlogn)
*	(1) ������ pivot�� ��´� - ���� y���� ���� ���� ��
*	(2) x�࿡ ���� ������ �������� ������ �Ѵ�.	- pivot �������� �ݽð� ���� ����
* 2) Processing (n)
*	(1) first = pivot, second = ������ ù��°�� �Ѵ�.
*	(2) ������ �ι�°�� next�� �Ѵ�.
*	(3) first�� second�� ���ÿ� �ִ´�.
*	(4-1) �� ��(second)�� ���� ����, ���� ��(second), top(first), next�� ���Ͽ� ccw�� �����Ѵ�.
		  �ݽð����(>0)�̸� second�� next�� ���ÿ� �ִ´�.
*	(4-2) ���� ccw�� �ð����(<0)�̸� second�� ���ÿ� ���� �ʰ�, pop�� �ѹ� �� �Ѵ�.
*		  �׸��� �̹��� ���� ��, top(������ first ���� ��), next�� ���Ͽ� ccw�� �����Ѵ�.
* 
* - ��ó�� �������� ��ǥ���� ccw�� �������� �����߱� ������, 4�� �������� ccw�� �ð�����̶��
*	second�� ���� ���ʿ� ������ �ǹ��Ѵ�.
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

#define POSITION pair<long long, long long>

// input
int N;

// �������� �迭 - ���� �տ� pivot ����
POSITION positions[100000];

// Processing���� ��� - positions �迭�� �ε����� ����
stack<int> stk;

POSITION operator- (POSITION _p1, POSITION _p2)
{
	return { _p1.first - _p2.first, _p1.second - _p2.second };
}
long long ccw(POSITION _pivot, POSITION _p1, POSITION _p2)
{
	POSITION v1 = _p1 - _pivot;
	POSITION v2 = _p2 - _pivot;
	return v1.first * v2.second - v1.second * v2.first;
}

long long distance(POSITION _a, POSITION _b)
{
	return pow(_a.first - _b.first, 2) + pow(_a.second - _b.second, 2);
}

// Y��ǥ ���� ����
bool compareY(POSITION _a, POSITION _b)
{
	if (_a.second < _b.second) return true;
	else if (_a.second > _b.second) return false;
	else
	{
		return _a.first < _b.first;
	}
}

// ccw�� �������� ����
// �� ������ ���ؼ��� ��Į�� ���� �̿��� cos���� �������� �Ǵ�,
// pivot�� �ش� ���� ���� ������ ������ ���⸦ ����� �� �ִ�.
bool compareCCW(POSITION _a, POSITION _b)
{
	long long ccwResult = ccw(positions[0], _a, _b);
	
	// �� ���� ������ ���� ������ ����� ���� ���� ��� (�� ����ó�� �߿�)
	if (ccwResult == 0)
		return distance(positions[0], _a) < distance(positions[0], _b);
	else  // �׷��� ���� ��� �� �ݽð� ������ �ƴ� ������ ������ ��ġ
	{
		return ccwResult > 0;
	}
}



int main()
{
	cin >> N;
	for (int n = 0; n < N; n++)
		cin >> positions[n].first >> positions[n].second;
	sort(positions, positions + N, compareY);	// p[0]�� pivot(Y��ǥ�� ���� ���� ��)�� ����
	sort(positions + 1, positions + N, compareCCW);	// p[0]�� ������.

	/*for (int n = 0; n < N; n++)
		cout << positions[n].first << ' ' << positions[n].second << endl;*/

	stk.push(0);
	stk.push(1);
	int next = 2;	// positions �迭 ������ �ε���

	// ��� ������ �� ���� ������
	while (next < N)
	{
		while (stk.size() > 1)
		{
			int second = stk.top();
			stk.pop();
			int first = stk.top();

			// ���� ccw�� <0�̶�� second�� ������ ä�� ���� �ܰ�� �����Ѵ�.
			// �׷��� �ʴٸ� second�� ������ ���·� �ݺ��Ѵ�.
			if (ccw(positions[first], positions[second], positions[next]) > 0)
			{
				stk.push(second);
				break;
			}
		}

		// ���� �������� �����Ѵ�.
		stk.push(next++);
	}
	
	cout << stk.size();


	return 0;
}