// ���� 7568�� ��ġ

// input: 1 <= N = ��� �� <= 50
//		  10 <= x, y = ������, Ű <= 200

// condition: Ű�� �����԰� ��� ũ�ٸ� �װ��� ��������� '��ġ�� ũ��' (�ʰ��� �ش�)
//			  ���� �Ѵ� �ʰ����� �ʴ´ٸ� ��ġ�� ������ �� �����Ƿ� ���� ����̴�.
//			  �ڽź��� ��ġ�� ū ��� �� +1�� ����̴�.

// ���Ʈ���� �˰���: ������ �Ǵ�, ���ǹ��� ���̽����� ��� �˻��ϴ� ���̴�.

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[3];
		cin >> arr[i][0] >> arr[i][1];
		arr[i][2] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		for (int f = 0; f < N; f++)
		{
			if (arr[i][0] < arr[f][0] && arr[i][1] < arr[f][1])
				arr[i][2] += 1;
		}
		cout << arr[i][2] << '\n';
	}

	for (int i = 0; i < N; i++) delete[] arr[i];
	delete[] arr;
}