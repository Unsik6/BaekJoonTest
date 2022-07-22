// ���� 1541�� �Ҿ���� ��ȣ

// input: ���ڿ� +, -�θ� �̷���� �� (���� <=50)
//		  �����ؼ� �� �� �̻��� �����ڰ� ��Ÿ���� ������, 5�ڸ����� ���� ���ڴ� ����.

// condition: ��ȣ�� ������ �ļ� �� ���� ���� �ּҷ� ������ �Ѵ�.

// ���� ���� �ּҰ� �Ƿ��� - ���� ���� Ŀ���Ѵ�.
// ��, ������ -�� ������ ���� -�� ���� ������ +������ �ϰ� �� ���� -�Ѵ�.
// -(a + b + c + ...) -

#include <iostream>
using namespace std;

void initiateArrForMakingNum(int* _arr, int _size = 5)
{
	for (int i = 0; i < _size; i++)
		_arr[i] = -1;
}

int powInt(int _x, int _y)
{
	int result = 1;
	for (int i = 0; i < _y; i++)
		result *= _x;
	return result;
}

int main()
{
	string formula;
	cin >> formula;


	int total = 0;
	int tempSumForSubproblem = 0;

	// making number
	int number = 0;
	int numberCnt = -1;
	int arrForMakingNum[5];
	initiateArrForMakingNum(arrForMakingNum);

	for (int i = formula.length() - 1; i >= 0; i--)
	{
		if (formula[i] >= '0' && formula[i] <= '9')
		{
			arrForMakingNum[++numberCnt] = formula[i] - '0';

			if (i == 0) // first Number
			{
				for (int i = 0; i <= numberCnt; i++)
				{
					number += powInt(10, i) * arrForMakingNum[i];
				}
				total += (number + tempSumForSubproblem);
			}
		}
		else  // operator
		{
			for (int i = 0; i <= numberCnt; i++)
			{
				number += powInt(10, i) * arrForMakingNum[i];
			}

			if (formula[i] == '+')
				tempSumForSubproblem += number;
			else
			{
				total -= (tempSumForSubproblem + number);
				tempSumForSubproblem = 0;
			}


			initiateArrForMakingNum(arrForMakingNum);
			number = 0;
			numberCnt = -1;
		}
	}
	
	cout << total;
}