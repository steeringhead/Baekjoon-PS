#include <iostream>
#include <vector>

using namespace std;

int N, M;
int destList[1000];
int adjArr[201][201];
int myParent[201];

int findNode(int x)
{
	if (myParent[x] != x)
	{
		return findNode(myParent[x]);
	}
	else
		return myParent[x];
}

void uinonNode(int x, int y)
{
	x = findNode(x);
	y = findNode(y);

	if (x < y)
		myParent[y] = x;
	else
		myParent[x] = y;
		
}

int main()
{
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
	{
		myParent[i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> adjArr[i][j];
			if (adjArr[i][j] == 1)
				uinonNode(i, j);
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> destList[i];
		
	}

	int oneValue = findNode(destList[0]);

	for (int i = 1; i < M; i++)
	{
		if (oneValue != findNode(destList[i]))
		{
			cout << "NO" << endl;
			return 0;
		}
		
	}

	cout << "YES" << endl;
	return 0;
	
}