#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N, M;
int map[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int maxValue = INT_MIN;

// Map을 Copy하는 함수
// BFS로 바이러스 갯수 확인하는 함수
// 벽 세울곳을 정해주는 함수까지.

void CopyMap(int (*a)[8], int (*b)[8])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

void BFS()
{
	int newMap[8][8];
	CopyMap(newMap, map);

	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (newMap[i][j] == 2)
			{
				Q.push({ i,j });
			}
		}
	}

	while (Q.empty() == false)
	{
		auto cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nX = cur.first + dx[i];
			int nY = cur.second + dy[i];

			if (nX < 0 || nY < 0 || nX >= 8 || nY >= 8)
				continue;
			if (newMap[nX][nY] == 0)
			{
				newMap[nX][nY] = 2;				
				Q.push({ nX,nY });
			}
		}
	}

	int safeArea = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (newMap[i][j] == 0)
				safeArea++;
		}
	}

	if (safeArea > maxValue)
		maxValue = safeArea;
	
}

void LandWall(int cnt)
{
	if (cnt == 3)
	{
		BFS();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				LandWall(cnt + 1);
				map[i][j] = 0;
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				LandWall(1);
				map[i][j] = 0;
			}
		}
	}

	cout << maxValue;
}