// ���� 2581�� �Ҽ�

#include <iostream>
#include <string>
using namespace std;

void arrSwap(string a, string b)
{
	string tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int N;
	cin >> N;
	string* arr = new string[N];
	int lenOfS = 0;
	int lenOfL = 0;

	// �Է°� ���ÿ� ���� ���� ����
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		
		// �� �� ���ڿ��� ����
		lenOfS = arr[0].length();
		
		// ���� �� ���� ���ڿ����� ª�ٸ� arr[i]�� �� ������ �ű�� ������ ��ĭ �� �ڷ�
		if (arr[i].length() <= lenOfS)
		{
			string tmp = arr[i];
			for (int f = i; f > 0; f--) arr[i] = arr[i-1];
			arr[0] = tmp;
		}
		// ���� ���̰� �߰� �������
		else if (arr[i].length() < lenOfL && arr[i].length() > lenOfS)
		{
			// ���̰� ���� �� ���� ��
			// �� �տ� �ְ� ������ �� ĭ�� �ڷ�
			for (int k = 0; k < i; k++)
			{
				if (arr[k].length() == arr[i].length())
				{
					string tmp = arr[i];
					for (int f = i; f > k; f--) arr[i] = arr[i - 1];
					arr[k] = tmp;
				}
			}
		}
		// ���̰� ���� ��� ��� ����

		// �ǵ� ���� �ֱ�
		lenOfL = arr[i].length();
	}

	
	

	for (int i = 0; i < N; i++) cout << arr[i] << endl;
}