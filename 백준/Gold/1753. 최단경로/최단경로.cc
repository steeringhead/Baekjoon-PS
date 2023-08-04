#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000
#define MAX 20001

using namespace std;

vector<pair<int,int>> adj[MAX];
int dist[MAX];

bool cmp(const pair<int,int>& a, const pair<int,int>& b)
{
	return a.second > b.second;
}

void dijkstra(int s)
{
	dist[s] = 0;
	priority_queue<pair<int, int>,vector<pair<int,int>>, decltype(&cmp)> pq(&cmp);

	pq.push(make_pair(s, 0));

	while (pq.empty() == false)
	{
		auto cur = pq.top();
		pq.pop();

		if (cur.second > dist[cur.first])
			continue;
		
		for (int i = 0; i < adj[cur.first].size(); i++)
		{
			auto now = adj[cur.first][i];
			if (now.second + cur.second < dist[now.first])
			{
				dist[now.first] = now.second + cur.second;
				pq.push(make_pair(now.first, cur.second + now.second));
			}
		}
	}
}


int main()
{
	int V, E, start;
	cin >> V >> E >> start;
	
	for (int i = 1; i <= V; i++)
	{
		dist[i] = INF;
	}

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	

	dijkstra(start);

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';

	}
}
