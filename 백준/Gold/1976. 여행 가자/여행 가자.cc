#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 201

int parent[MAX];
int dest[1001];
int adj[MAX][MAX];

int find(int x)
{
	if (x != parent[x])
	{
		return parent[x] = find(parent[x]);
	}
	else
		return x;
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if (x == y)
		return;

	if (x > y)
	{
		parent[x] = y;
	}
	else
		parent[y] = x;
}



int main()
{
	int N,M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> adj[i][j];
			if (adj[i][j] == 1)
				Union(i, j);
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> dest[i];
	}

	int goal = find(dest[1]);
	
	for (int i = 2; i <= M; i++)
	{
		if (find(dest[i]) != goal)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}