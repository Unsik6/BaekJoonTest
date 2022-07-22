// ���� 2138�� ������ ����ġ

// input: �迭�� ���� N (2 <= N <= 100,000)
//		  arr[i]�� ���� (0, 1)
//		  ���ϴ� arr[i]�� ���� (0, 1)

// condition: i��° ����ġ�� ���� ���, i-1, i, i+1�� �ٲ��. �� ���� ���� 1���� ���θ� �ٲ��.
//			  ���� �迭�� ���¸� ���ϴ� ���·� �ٲ� �� �ִ� �ּ����� ����ġ ���� Ƚ���� ����϶�. 
//			  �Ұ����� ��� -1 ���

// i��° ������ ����Ͽ� i+1��° ����ġ�� �۵��Ѵ�.
// ������ ������ �ٸ��� ����ġ�� �Ҵ�.
// �̷��� �ϸ� �������� �������� ������ ����� ������ ������ ���� �ʴ´�.
// ��, 2���� ���̽��� ���ؾ� �Ѵ�. 1�� ������ Ű�� ���� Ű�� �ʴ� ���

#include<iostream>
using namespace std;

int main()
{
	int N;
	string curStr, tarStr;
	cin >> N >> curStr >> tarStr;;
	
	// case 1
	string temp = curStr;
	int cnt1 = 1;
	temp[0] = (temp[0] == '0' ? '1' : '0');
	temp[1] = (temp[1] == '0' ? '1' : '0');

	for (int i = 1; i < N; i++)
	{
		if (temp[i - 1] != tarStr[i - 1])
		{
			temp[i - 1] = (temp[i - 1] == '0' ? '1' : '0');
			temp[i] = (temp[i] == '0' ? '1' : '0');
			if(i < N - 1) temp[i + 1] = (temp[i + 1] == '0' ? '1' : '0');
			cnt1++;
		}
	}
	if (temp[N - 1] != tarStr[N - 1]) cnt1 = -1;

	// case 2
	int cnt2 = 0;
	for (int i = 1; i < N; i++)
	{
		if (curStr[i - 1] != tarStr[i - 1])
		{
			curStr[i - 1] = (curStr[i - 1] == '0' ? '1' : '0');
			curStr[i] = (curStr[i] == '0' ? '1' : '0');
			if (i < N - 1) curStr[i + 1] = (curStr[i + 1] == '0' ? '1' : '0');
			cnt2++;
		}
	}
	if (curStr[N - 1] != tarStr[N - 1]) cnt2 = -1;

	if (cnt1 == -1) cout << cnt2;
	else if (cnt2 == -1) cout << cnt1;
	else cout << (cnt1 < cnt2 ? cnt1 : cnt2);
}