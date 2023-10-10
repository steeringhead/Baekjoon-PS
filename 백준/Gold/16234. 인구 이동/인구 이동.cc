#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, L, R;

int map[50][50];
int visited[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Node
{
	int x;
	int y;
	int val;
	Node(int a, int b, int c)
	{
		x = a;
		y = b;
		val = c;
	}
};

void Init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = 0;
		}
	}
}

void DFS(int x,int y,vector<Node>& v)
{
	int curVal = map[x][y];

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] == 1)
			continue;
		if (abs(curVal - map[nx][ny]) < L || abs(curVal - map[nx][ny]) > R)
			continue;

		v.push_back({ nx,ny,map[nx][ny] });
		visited[nx][ny] = 1;
		DFS(nx, ny, v);
	}

	
}


int main()
{
	cin >> N >> L >> R;
	int answer = 0;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	while (true)
	{		
		bool flag = false;
		vector<Node> tv;
		for (int i = 0; i < N; i++)
		{			
			for (int j = 0; j < N; j++)
			{
				vector<Node> v;

				if (visited[i][j] == 0)
				{
					DFS(i, j, v);
				}

				if (v.empty() == false)
				{
					flag = true;
					int tmp = 0;
					for (int i = 0; i < v.size(); i++)
					{
						Node cur = v[i];
						tmp += cur.val;
					}

					tmp = tmp / v.size();
					for (int i = 0; i < v.size(); i++)
					{
						v[i].val = tmp;
						tv.push_back({ v[i].x,v[i].y,tmp });
					}
				}
			}

			
		}
		for (int i = 0; i < tv.size(); i++)
		{
			Node cur = tv[i];
			map[cur.x][cur.y] = cur.val;
		}

		if (flag == false)
			break;
		else
		{
			answer++;
			Init();
		}
	}
	
	cout << answer;

}