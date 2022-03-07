// ���� 1026�� ����

// input: �迭 A, B�� ���� N(�ڿ���) (1<= N <=50)
//		  �迭 A�� ���, �迭 B�� ��� (0 <= x <= 100)

// condition: S = A[0]*B[0] + ... + A[N-1]*B[N-1]�� �ּڰ� ���
//			  A�� ��ҵ��� ��ġ�� ��迭�� �� ������ B�� �� �� ����.
//			  B�� ���� �������� A�� ���� Ŀ�� ���� ���� ���� ���´�.


#include<iostream>
#include<algorithm>
using namespace std;

bool decreasingOrder(int _a, int _b)
{
	return _a > _b;
}

int main()
{
	int N;
	cin >> N;
	int* A = new int[N];
	int* B = new int[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	sort(A, A + N);
	sort(B, B + N, decreasingOrder);
	
	int s = 0;
	for (int i = 0; i < N; i++)
		s += A[i] * B[i];
	cout << s;

	delete[] A;
	delete[] B;
	return 0;
}