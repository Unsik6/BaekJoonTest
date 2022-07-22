// ���� 10989�� �� �����ϱ�3

// input: 1 <= N = ���� ���� <= 10,000,000
//		  1<= x <= 10,000

// using Counting Sort Algorithm


#include<iostream>
using namespace std;

int main()
{
	// C�� C++�� ǥ�� stream�� ����ȭ�� ��� cin�� cout�� �ӵ��� ������ �ð��ʰ��� ��Ÿ���� �ʴ´�.
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, n;
	cin >> N;
	int* count = new int[10001]{ 0 };
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		count[n]++;
	}
	for (int i = 1; i < 10001; i++)
		for (int f = 0; f < count[i]; f++)
			cout << i << '\n';
	return 0;
}


// ù��°: ���� ����Ʈ�� �̿��� Counting Sort : �޸� �ʰ�
/*
#include <iostream>
using namespace std;

class Node
{
public:
	int num = 0;
	int cnt = 0;
	int cntSum = 0;
	Node* next = nullptr;
	Node() {}
	Node(int n = 0, int c = 0, Node* ptr = nullptr) : num(n), cnt(c), next(ptr) {}
};

class MList
{
public:
	Node* head = nullptr;
	MList() {}
	MList(Node* ptr) :head(ptr) {}
	void insert(Node* node)
	{
		bool isChange = false;
		Node* tmp = head;
		Node* pre = nullptr;
		while (tmp != nullptr)
		{
			if (tmp->num > node->num)
			{
				node->next = tmp;
				if (tmp == head) head = node;
				if (pre != nullptr) pre->next = node;
				isChange = true;
				break;
			}
			pre = tmp;
			tmp = tmp->next;
		}
		if (!isChange)
		{
			if (pre == nullptr && head != nullptr) head->next = node;
			else if(pre != nullptr) pre->next = node;
		}
	}

	void makeCntSum()
	{
		head->cntSum = head->cnt - 1;
		Node* tmp = head->next;
		Node* pre = head;
		while (tmp != nullptr)
		{
			tmp->cntSum = tmp->cnt + pre->cntSum;
			pre = tmp;
			tmp = tmp->next;
		}
	}

	Node* search(int n)
	{
		Node* tmp = head;
		while (tmp != nullptr)
		{
			if (tmp->num == n)
				return tmp;
			
			tmp = tmp->next;
		}
		return nullptr;
	}
};

int main()
{
	int N;
	cin >> N;
	int* numbers = new int[N];
	for (int i = 0; i < N; i++) cin >> numbers[i];
	Node* Head = new Node(numbers[0], 1);
	MList* List = new MList(Head);

	
	for (int i = 1; i < N; i++)
	{
		Node* searchReuslt = List->search(numbers[i]);
		if (searchReuslt != nullptr) searchReuslt->cnt++;
		else
		{
			Node* newNode = new Node(numbers[i], 1);
			List->insert(newNode);
		}
	}
	List->makeCntSum();
	
	int* result = new int[N];
	for (int i = N - 1; i >= 0; i--)
	{
		Node* equal = List->search(numbers[i]);
		result[equal->cntSum] = numbers[i];
		equal->cntSum--;
	}
	for (int i = 0; i < N; i++) cout << result[i] << '\n';
}
*/