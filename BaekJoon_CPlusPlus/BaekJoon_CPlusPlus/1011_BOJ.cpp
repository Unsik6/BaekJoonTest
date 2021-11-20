// ���� 1011�� Fly me to the Alpha Centauri

// Input: T = �׽�Ʈ ���̽�, 0 <= x = �����ǥ < y = ���� ��ǥ < 2^31
// condition: ù �̵��� ������ �̵��� 1�̴�.
//			  i��°�� k��ŭ �̵��ߴٸ� i+1��° �̵��� k-1, k, k+1 ��ŭ�� �̵��� �� �ִ�.

// ù��° �õ�: �ð� �ʰ�

// 2^31���� �����Ƿ� int ���� ���� �ִ�.
// ���� ����ȭ�� ��δ� 1�� �����ؼ� 1�� ������ �Ƕ�̵������� �ö󰡴� ���̴�.
// �ֳ��ϸ� �ּ������� �̵��ؾ� �ϱ� ������ �ѹ��� �ִ��� ���� �̵��ؾ� �ϱ� �����̴�.
// length = y - x
// ���� ��Ȯ�ϰ� �Ƕ�̵������� �̵��� ���, length��
// length = n(n+1)/2 + n(n-1)/2 (n�� �ѹ��� ���� �ָ� �̵��� �Ÿ�)
//		  = n^2
// �׷��Ƿ� ���� length�� ���� �ʴ� �ִ��� n�� ã�´�.
// ���Ŀ��� ���� ���(Q2839) ������ ����ϴ�. �ٸ�, �ִ� ������ ��� �ٲ��.
// length - n^2�� ���� ������� ���� ��, ���� ������ (n-2), (n-1), n ũ���� �ָӴϿ� ��� ���̴�.
// �̶� ���� �ִ��� ���� ���� �ָӴϷ� ��� ���̴�.
// ���� (n-2), (n-1), n�� �ָӴϷ� �� ������ ������ �� ���ٸ�, n--�� �ϰ�
// �ٽ� (n-2), (n-1), n�� �������� �ָӴϷ� ������.
// ���� n = 4�� ��, length - n^2 = 10�̶�� 4, 4, 2���� ���� �� �ִ�.
// �ٸ�, �̷� ��� �̵� �Ÿ��� [1, 2, 3, 4, 4, 2. 3. 2. 1]�� �ȴ�.
// �̷� ���, [4, 2] ������ ��ȯ�� �Ұ����������� 3, 3���� ġȯ�� �����ϹǷ� �������.
// �ָӴ� �߿� n ũ���� �ָӴϿ� n-2�� �ָӴϰ� �ִٸ�, n-1�� �ָӴϰ� �ݵ�� 1�� �̻� �־�� ������
// �ڵ����� ġȯ�Ǵ� �����ص� �ȴ�.

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	// input
//	int T;
//	cin >> T;
//	int* arrX = new int[T];
//	int* arrY = new int[T];
//	for (int t = 0; t < T; t++) cin >> arrX[t] >> arrY[t];
//
//	// Test repitition
//	for (int t = 0; t < T; t++)
//	{
//		int length = arrY[t] - arrX[t];
//		if (length < 4)
//		{
//			cout << length << endl;
//			continue;
//		}
//		// find maximum distance
//		int n = 1;	// n >= 1
//		int nCnt = 0;
//		int n_1Cnt = 0;
//		int n_2Cnt = 0;
//		while (n * n <= length) n++;
//		n--;
//		if (length == n * n)
//		{
//			cout << 2 * n - 1;
//			continue;
//		}
//		int rest = 0;
//		while (n > 1)
//		{
//			rest = length - n * (n - 1);
//			nCnt = rest / n;
//			while (nCnt >= 0)
//			{
//				rest -= n * nCnt;
//				n_1Cnt = rest / (n - 1);
//				rest -= (n - 1) * n_1Cnt;
//				if (n > 2)
//				{
//					while (n_1Cnt >= 0)
//					{
//						n_2Cnt = rest / (n - 2);
//						rest -= (n - 2) * n_2Cnt;
//						if (rest == 0) break;
//						else
//						{
//							n_1Cnt--;
//							rest = length - n * (n - 1);
//							rest -= n * nCnt;
//							rest -= (n - 1) * n_1Cnt;
//						}
//					}
//				}
//				if (rest == 0) break;
//				else
//				{
//					nCnt--;
//					rest = length - n * (n - 1);	// rest �ʱ�ȭ
//				}
//			}
//			if (rest == 0) break;
//			else n--;
//		}
//		cout <<  2 * (n - 1) + nCnt + n_1Cnt + n_2Cnt << endl << endl;
//	}
//}