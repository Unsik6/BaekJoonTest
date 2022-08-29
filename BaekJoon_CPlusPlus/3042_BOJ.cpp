/* ���� 3042�� Ʈ���÷�
*
* Input: �׸����� ũ�� N (3 <= N <= 100)
*		 N���� �ٿ� �׸����� �� �࿡ ���� ���� (���ĺ� �Ǵ� . ) (���ĺ��� �ߺ� X)

* Output: ���� ���� �� ���ĺ��� 3�� ���̸� Ʈ���÷��̴�. Ʈ���÷��� ������ ���Ͽ���.
*
* �� ���� ������ �߿����� �ʴ�. �� ���� ���� ���Ⱑ �������� �ľ��Ѵ�.
*/

#include<iostream>
#include <utility>
#include<vector>
using namespace std;

#define pos pair<double, double>

double cal(pos a, pos b) {
	return (b.second - a.second) / (b.first - a.first);
}

int main() {
	int n; cin >> n;
	vector<pos>arr;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char k; cin >> k;
			if (k != '.')
				arr.push_back({ (double)i,(double)j });
		}
	}

	int res = 0;
	int len = arr.size();
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			for (int k = j + 1; k < len; k++) {
				if (cal(arr[i], arr[j]) == cal(arr[i], arr[k])
					&& cal(arr[j], arr[k]) == cal(arr[i], arr[k]))
					res++;
			}
		}
	}
	cout << res;
	return 0;
}
