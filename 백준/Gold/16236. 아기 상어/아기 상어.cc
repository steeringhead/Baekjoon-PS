#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;


struct Node
{
	int canEat;
	int dist;
	Node() : canEat(0), dist(0) {}
	Node(int x, int y)
	{
		canEat = x;
		dist = y;
	}

};

struct MI
{
	int x;
	int y;
	int dist;
	MI(int a, int b, int c)
	{
		x = a;
		y = b;
		dist = c;
	}
};

int N;
int space[20][20];
int visited[20][20];
Node info[20][20];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int res = 0;
int sSize = 2;
int cnt = -1;

void InitVis()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = 0;
		}
	}
}

void InitInfo()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			info[i][j] = Node(0,0);
		}
	}
}

void BFS(int x,int y,int dist)
{
	InitVis();
	InitInfo();
	visited[x][y] = 1;
	space[x][y] = 0;
	queue<MI> Q;
	Q.push({ x,y,dist});

	if (space[x][y] != 9)
	{
		cnt++;
		if (cnt == sSize)
		{
			sSize++;
			cnt = 0;
		}
		
	}

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nX = cur.x + dx[i];
			int nY = cur.y + dy[i];
			int d = cur.dist;

			if (nX < 0 || nX >= N || nY < 0 || nY >= N || visited[nX][nY] == 1)
				continue;

			if (space[nX][nY] > sSize)
			{
				continue;
			}

			if (space[nX][nY] != 0 && space[nX][nY] < sSize)
			{
				info[nX][nY] = Node(1, d + 1);
			}
			else
			{
				info[nX][nY] = Node(0, d + 1);
			}

			Q.push(MI(nX, nY, d + 1));
			visited[nX][nY] = 1;
		}
	}
	//시작점 BFS가 끝나면 가능한 지점에서 다시 BFS 시작
	int nX, nY, d = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (info[i][j].canEat == 1 && info[i][j].dist < d)
			{
				nX = i;
				nY = j;
				d = info[i][j].dist;
			}
		}
	}
	if (d == INT_MAX)
		return;
	else
	{
		res = d;
		BFS(nX, nY, d);
	}
}

int main()
{
	cin >> N;
	int sX, sY;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				sX = i;
				sY = j;
			}
		}
	}

	BFS(sX, sY, 0);

	if (res == 0)
		cout << 0;
	else
		cout << res;
}