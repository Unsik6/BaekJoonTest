/* 백준 3049번 다각형의 대각선
*
* Input: 볼록 다각형의 각 수 N
*		 (볼록 다각형: 내각이 180을 넘지 않는 다각형)

* Output: 대각선 2개만 교차하는 교차점의 개수
* 
* 대각선 두개로 이루어진 교차점이므로 대각선 두개가 필요하다.
* 대각선 두개는 4개의 꼭지점을 필요로 한다.
* nC4
*/

#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	std::cout << N * (N - 1) * (N - 2) * (N - 3) / 2 / 3 / 4;
}