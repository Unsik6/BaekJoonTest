// ���� 2630�� ������ �����

// input: ��ü ������ �Ѻ��� ���� N = 2, 4, 8, 16, 32, 64, 128
//        ���� ���ٺ��� ���ʷ� �Ͼ���� 0, �Ķ����� 1

// condition: ���� �����̰� ���� ����θ� �̷���� ���� �ʴٸ� ��ü�� 1/4�Ѵ�.


#include <iostream>
#include<utility>
using namespace std;

pair<int, int>& operator+=(pair<int, int>& _a, const pair<int, int>& _b)
{
	_a.first += _b.first;
	_a.second += _b.second;	
	return _a;
}


pair<int, int> numberOfWhiteAndBlue(int** _arr, int _startRowIdx, int _StartColumnIdx, int _n)
{
	if (_n == 1)
	{
		return make_pair(!(_arr[_startRowIdx][_StartColumnIdx]), _arr[_startRowIdx][_StartColumnIdx]);
	}
	else
	{
		pair<int, int> wb = make_pair(0, 0);
		int p = _arr[_startRowIdx][_StartColumnIdx];
		for (int i = 0; i < _n; i++)
		{
			for (int j = 0; j < _n; j++)
			{
				if (_arr[_startRowIdx + i][_StartColumnIdx + j] != p)
				{
					pair<int, int> temp = make_pair(0, 0);

					temp = numberOfWhiteAndBlue(_arr, _startRowIdx, _StartColumnIdx, _n / 2);
					wb += temp;

					temp = numberOfWhiteAndBlue(_arr, _startRowIdx + _n/2, _StartColumnIdx, _n / 2);
					wb += temp;

					temp = numberOfWhiteAndBlue(_arr, _startRowIdx, _StartColumnIdx + _n / 2, _n / 2);
					wb += temp;

					temp = numberOfWhiteAndBlue(_arr, _startRowIdx + _n / 2, _StartColumnIdx + _n / 2, _n / 2);
					wb += temp;

					return wb;
				}
			}	
		}
		return make_pair(!(_arr[_startRowIdx][_StartColumnIdx]), _arr[_startRowIdx][_StartColumnIdx]);
	}
}

int main()
{
	int N;
	cin >> N;
	int** arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	pair<int, int> wb = numberOfWhiteAndBlue(arr, 0, 0, N);
	cout << wb.first << '\n' << wb.second;

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

}