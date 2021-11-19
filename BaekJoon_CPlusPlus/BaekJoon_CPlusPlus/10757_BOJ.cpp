// ���� 10757�� ū �� A+B

// Input: 0 < A, B < 10^10000 (A, B�� ����)

// ������ �ڷ����� 10^10000������ ���ڸ� ǥ���� �� ����.
// ���ڿ��� ǥ���ؾ� �Ѵ�.

// ASCII
// 0: 48 ~ 9: 57

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string A, B, result;
	cin >> A >> B;
	int longerLength = static_cast<int>(A.length() > B.length() ? A.length() : B.length());
	int resultLength = longerLength + 2;
	result.resize(resultLength);
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	bool upper = false;
	int pos = 0;
	for (pos = 0; pos < static_cast<int>(result.length()) - 1; pos++)
	{
		int ofA{ 48 }, ofB{ 48 };
		if (pos < static_cast<int>(A.length())) ofA = A[pos];
		if (pos < static_cast<int>(B.length())) ofB = B[pos];
		int add = (upper ? (ofA - 48) + (ofB - 48) + 1 : (ofA - 48) + (ofB - 48));
		if (add > 9)
		{
			result[pos] = add + 38;
			upper = true;
		}
		else
		{
			result[pos] = add + 48;
			upper = false;
		}
	}
	int back = pos - 1;
	if (result[back] == 48)
	{
		result.resize(back);
	}
	else result.resize(pos);
	// �� if-else���� ���� result�� C���ڿ��̶�� �Ʒ��� if���� ����Ѵ�.
	/*if (result[back] == 48)
	{
		result.resize(pos);
		result[back] = '\0';
	}
	else result[result.length() - 1] = '\0';*/


	reverse(result.begin(), result.end());

	cout << result << endl;
}
