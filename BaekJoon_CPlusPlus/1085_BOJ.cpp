// ���� 1085�� ���簢������ Ż��

// input: Ż���ؾ� �� ���簢�� (w, h) 1 <= w, h <= 1,000
//		  �Ѽ��� ��ġ (x, y) 1<= x <= w-1, 1<= y <= h-1
//		  w, h, x, y �� ����

// Ż���ϴ� ���� ���� ����� �׳� ���� �Ǵ� �������� ���� ����� �������� ���� ���̴�.

#include<iostream>
int main()
{
	int x, y, w, h;
	std::cin >> x >> y >> w >> h;
	int min = x;
	if (w - x < min) min = w - x;
	if (y < min) min = y;
	if (h - y < min) min = h - y;
	if (min < 0) min *= -1;
	std::cout << min;
}