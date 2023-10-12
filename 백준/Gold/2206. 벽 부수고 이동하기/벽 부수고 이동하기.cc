#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int map[1000][1000];
int visited[1000][1000];
int wallVisited[1000][1000];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> list;

bool cmp(int x, int y)
{
	return x < y;
}

struct Info 
{
	int x;
	int y;
	int cnt;
	bool wall;
	Info(int a, int b, int c,bool d)
	{
		x = a;
		y = b;
		cnt = c;
		wall = d;
	}
};

void BFS(int x,int y)
{
	queue<Info> q;
	visited[x][y] = 1;
	q.push({ x,y,0,false });

	while (q.empty() == false)
	{
		Info cur = q.front();
		q.pop();

		if (cur.x == N - 1 && cur.y == M - 1)
			list.push_back(cur.cnt+1);

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (cur.wall == false && visited[nx][ny] == 1)
				continue;

			if (cur.wall == true && wallVisited[nx][ny] == 1)
				continue;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			
			if (map[nx][ny] == 1 && cur.wall == true)
				continue;

			if (map[nx][ny] == 1 && cur.wall == false)
			{
				q.push({ nx,ny,cur.cnt+1,true });
				wallVisited[nx][ny] = 1;
				continue;
			}

			q.push({ nx,ny,cur.cnt+1,cur.wall });
			if (cur.wall == false)
			{
				visited[nx][ny] = 1;
			}
			else
			{
				wallVisited[nx][ny] = 1;
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
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = tmp[j] - '0';
		}
	}
	
	BFS(0, 0);	
	sort(list.begin(), list.end(), cmp);
	
	if (list.empty() == true)
		cout << -1;
	else
		cout << list[0];
	
}