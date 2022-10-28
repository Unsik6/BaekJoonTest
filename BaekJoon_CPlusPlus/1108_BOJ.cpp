/* ���� 1108 �˻� ����
*
* Input: ��ũ ������ �� N (1 <= N <= 50)
*		 N���� �ٿ� ��ũ ����
*		 L i l1 l3 ... li ( li ... li�κ��� L�� ���� ��ũ�� ����, ��� ��ũ�� �̸��� ���ڿ� S(|S| <= 50)�̴�. )
*						  (0 <= i <= 24)
*		 ������ �˰��� �ϴ� ��ũ �̸� (����� ��ũ ������ ���Ե�)
* 
*		 1) ��� ��ũ�� �ʱ� ������ 1�̴�.
*		 2) V -> W ��ũ�� �ִ� ��� V�� ������ W�� ���Ѵ�.
*		 3) ���� V ~> W�� �����Ѵٸ� W->V�� ���� ���� �̵��� ���� �ʴ´�.

* Output: ������ �˰��� �ϴ� ��ũ �̸��� ����
*/

// 2)�� ������ ���� ���������� �̿��Ѵ�.
// 3)�� ������ ���� SCC�� �̿��Ѵ�.
// ��ũ �̸��� �ؽ��Ͽ� �ε����� �����Ѵ�.

// ���μ���
// 1. �׷��� ����
// 2. SCC ���
// 3. ���� SCC�� �ִ� ��� ���� ���� ����
// 3. �������� �� ���� �ο�

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define UM_SI unordered_map<string, int>
#define INT_VEC vector<int>

// input
int iLinkNum;

// output
long long arrLinkScores[1250];	// ���� ������ 25*50 = 1250��.

// DataStructure
UM_SI mapLinks;				// ���� �ؽ�
INT_VEC vecGraph[1250];		// �׷���
INT_VEC vecGraphT[1250];	// ���� ������ �׷���
INT_VEC vecGraphN[1250];	// SCC �� ���� ������ �׷���
INT_VEC vecGraphNT[1250];	// SCC �� ������ �����ϰ�, ������ ������ �׷���

// For SCC
bool arrVisited[1250]{ false };		// DFS ������ �湮���� �Ǵ�
bool arrFinished[1250]{ false };	// DFS ������ ���Ῡ�� �Ǵ�
void resetDFSArr()
{
	for (int i = 0; i < iLinkNum; i++)
		arrVisited[i] = arrFinished[i] = false;
}
stack<int> stkAncestors;	// DFS�� ����
stack<int> stkFinished;		// DFS ���� ������ ����Ǵ� ����
int arrSCCL[1250];

// For Topological Sorting
int arrIndegSort[1250];
bool compVt(int _iVt1, int _iVt2)
{
	return vecGraphNT[_iVt1].size() < vecGraphNT[_iVt2].size();
}
int arrTPSort[1250];

int main()
{
	// input
	int iVtNum, iIndegNum;
	string strDst, strSrc;

	cin >> iVtNum;
	int iVtIdx = 0;	// ������ ���� �ε���
	for (int i = 0; i < iVtNum; i++)
	{
		cin >> strDst >> iIndegNum;

		// strDst�� �ؽÿ� ����� ���� ���ٸ� �����Ѵ�.
		if (mapLinks.find(strDst) == mapLinks.end())
			mapLinks[strDst] = iVtIdx++;

		for (int j = 0; j < iIndegNum; j++)
		{
			cin >> strSrc;
			if (mapLinks.find(strSrc) == mapLinks.end())
				mapLinks[strSrc] = iVtIdx++;

			// �׷����� �ֱ�
			vecGraph[mapLinks[strSrc]].push_back(mapLinks[strDst]);
			vecGraphT[mapLinks[strDst]].push_back(mapLinks[strSrc]);
		}
	}

	// ��ũ ����
	iLinkNum = mapLinks.size();

	// initiate Scores
	for (int i = 0; i < iLinkNum; i++)
		arrLinkScores[i] = 1;

	// Construct SCC
	// first DFS
	for (int i = 0; i < iLinkNum; i++)
	{
		if (!arrVisited[i])
		{
			stkAncestors.push(i);
			while (!stkAncestors.empty())
			{
				int iCurVt = stkAncestors.top();

				if (arrVisited[iCurVt])
				{
					stkAncestors.pop();
					if (!arrFinished[iCurVt])
					{
						stkFinished.push(iCurVt);
						arrFinished[iCurVt] = true;
					}
					continue;
				}
				else
					arrVisited[iCurVt] = true;

				for (int iAdjIdx = 0; iAdjIdx < vecGraph[iCurVt].size(); iAdjIdx++)
				{
					int iAdjVt = vecGraph[iCurVt][iAdjIdx];
					if (!arrVisited[iAdjVt])
						stkAncestors.push(iAdjVt);
				}
			}
		}
	}

	resetDFSArr();
	// second DFS
	while (!stkFinished.empty())
	{
		int iStartVt = stkFinished.top();
		stkFinished.pop();
		
		if (arrVisited[iStartVt])
			continue;

		stkAncestors.push(iStartVt);
		while (!stkAncestors.empty())
		{
			int iCurVt = stkAncestors.top();
			stkAncestors.pop();

			arrVisited[iCurVt] = true;
			arrSCCL[iCurVt] = iStartVt;

			for (int iAdjIdx = 0; iAdjIdx < vecGraphT[iCurVt].size(); iAdjIdx++)
			{
				int iAdjVt = vecGraphT[iCurVt][iAdjIdx];
				if (!arrVisited[iAdjVt])
					stkAncestors.push(iAdjVt);
			}
		}
	}

	// construct new Graph
	for (int i = 0; i < iLinkNum; i++)
	{
		for (int j = 0; j < vecGraph[i].size(); j++)
		{
			int iAdjVt = vecGraph[i][j];
			if (arrSCCL[i] != arrSCCL[iAdjVt])
			{
				vecGraphN[i].push_back(iAdjVt);
				vecGraphNT[iAdjVt].push_back(i);
			}
		}
	}
	
	// Topological Sorting
	// Indeg Sort
	// initialize
	for (int i = 0; i < iLinkNum; i++)
		arrIndegSort[i] = i;

	std::sort(arrIndegSort, arrIndegSort + iLinkNum, compVt);

	resetDFSArr();
	// DFS
	for (int i = 0; i < iLinkNum; i++)
	{
		int iStartVt = arrIndegSort[i];

		if (arrVisited[iStartVt])
			continue;

		stkAncestors.push(iStartVt);
		while (!stkAncestors.empty())
		{
			int iCurVt = stkAncestors.top();

			if (arrVisited[iCurVt])
			{
				stkAncestors.pop();
				if (!arrFinished[iCurVt])
				{
					stkFinished.push(iCurVt);
					arrFinished[iCurVt] = true;
				}
				continue;
			}
			else
				arrVisited[iCurVt] = true;
			

			for (int iAdjIdx = 0; iAdjIdx < vecGraphN[iCurVt].size(); iAdjIdx++)
			{
				int iAdjVt = vecGraphN[iCurVt][iAdjIdx];
				if (!arrVisited[iAdjVt])
				{
					stkAncestors.push(iAdjVt);
				}
				
			}
		}
	}

	// Score
	for (int i = 0; i < iLinkNum; i++)
	{
		int iCurVt = stkFinished.top();
		stkFinished.pop();
		for (int iAdjIdx = 0; iAdjIdx < vecGraphN[iCurVt].size(); iAdjIdx++)
		{
			int iAdjVt = vecGraphN[iCurVt][iAdjIdx];
			arrLinkScores[iAdjVt] += arrLinkScores[iCurVt];
		}
	}

	string strTarget;
	cin >> strTarget;
	cout << arrLinkScores[mapLinks[strTarget]];

	return 0;
}