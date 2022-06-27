/* ���� 25206�� ���� ������ // IUPC #2
*
* Input: 20�ٿ� ���� ġ���̰� ������ ���������� �����, ����, ����� �������� ���еǾ� �־�����.
*		 1) 1 <= ����� ���� <= 50
*		 2) ������� ���ĺ� ��ҹ��� �Ǵ� ���ڷθ� �̷���� ������, ���� ����. ��� ������� ���� �ٸ���
*		 3) ������ 1.0, 2.0, 3.0, 4.0 �� �ϳ��̴�.
*		 4) ����� A+, A0, B+, B0, C+, C0, D+, D0, F, P �� �ϳ��̴�.
*		 5) ��� �� ������ ����� P�� �ƴ��� ����ȴ�.
*
* Output: ���������� ����Ѵ�. ������� ������� �Ǵ� �������� 10^(-4) �����̸� �������� �����Ѵ�.
*		  ���������� �������� (���� x ��������)�� ���� ������ ������ ���� ���̴�.
*/


#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double ret = 0;
	string name, grade;
	float each = 0, fGrade;
	float sum = 0;

	for (int i = 0; i < 20; i++)
	{
		cin >> name >> each >> grade;
		
		if (grade == "A+") fGrade = 4.5;
		else if (grade == "A0") fGrade = 4.0;
		else if (grade == "B+") fGrade = 3.5;
		else if (grade == "B0") fGrade = 3.0;
		else if (grade == "C+") fGrade = 2.5;
		else if (grade == "C0") fGrade = 2.0;
		else if (grade == "D+") fGrade = 1.5;
		else if (grade == "D0") fGrade = 1.0;
		else if (grade == "F") fGrade = 0.0;
		else continue;

		ret = ret + (fGrade * each) * pow(10, 4);
		sum += each;
	}

	/*cout << fixed << setprecision(6);*/
	ret /= sum;
	ret /= pow(10, 4);
	cout << ret;


	return 0;
}