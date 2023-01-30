/* ���� 15649 N�� M(1)
*
*Input: �ڿ��� ���� N, �� �ڿ��� ���� M (1 <= M <= N <= 8)

* Output: 1~N�� ������ �ߺ� ���� M�� ���� ��� ���� ���
*/
// �ð������� 1�������� N�� M�� �۾Ƽ� ��Ʈ��ŷ���� Ǫ�� ����
// ����� ���� �ִ� 8!=40320�̸� �� �ܰ踶�� ������� ���� ���ڸ� Ȯ���ؾ� �ϹǷ� 8*8!�� �ȴ�.

#include <iostream>
using namespace std;

int N, M;
bool inputs[9]{ false };
int outputs[9];

void solution(int _seq)
{
	// M�� ���δ� Ȯ�������� ���
	if (_seq > M)
	{
		for (int i = 1; i <= M; i++)
			cout << outputs[i] << ' ';
		cout << '\n';
		return;
	}

	// ��� ���� �� �߿� ���� ���� �ź��� ����
	for (int i = 1; i <= N; i++)
	{
		// false�� ���
		if (!inputs[i])
		{
			inputs[i] = true;	// ����Ѵ� ����
			outputs[_seq] = i;	// ������ _seq��° ���ڿ� �ֱ�
			solution(_seq + 1);	// ���� ���� ��ȣ��
			
			// �̹� �ܰ���� �� ���������, ���� ��츦 ���� �������
			inputs[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;
	solution(1);
	return 0;
}