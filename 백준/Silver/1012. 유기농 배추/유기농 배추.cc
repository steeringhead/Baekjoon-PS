#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[50][50];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int cnt= 0;

int T, M, N, K;

void DFS(int x,int y)
{	
	map[x][y] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nextX = dx[i] + x;
		int nextY = dy[i] + y;
		
		if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
			continue;

		if (map[nextX][nextY] == 1)
			DFS(nextX, nextY);
	}
}

int main()
{

	cin >> T;
	while (T > 0)
	{
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
					continue;
				else
				{
					cnt++;
					DFS(i, j);
				}

			}
		}

		cout << cnt << '\n';
		T--;
		cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				map[i][j] = 0;
			}
		}
	}
	
}