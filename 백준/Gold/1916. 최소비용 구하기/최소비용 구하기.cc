#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, M;
int dist[1001];

struct Node
{
	int node;
	int dist;
	Node(int a, int b)
	{
		node = a;
		dist = b;
	}
	bool operator<(const Node& other) const
	{
		return dist > other.dist;
	}
};

void Init()
{
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INT_MAX;
	}
}

void dijkstra(int s, int e, vector<vector<pair<int, int>>>& adj)
{
	dist[s] = 0;
	priority_queue<Node> pq;
	pq.push(Node(s, 0));

	while (pq.empty() == false)
	{
		Node cur = pq.top();
		pq.pop();
		if (dist[cur.node] < cur.dist)
			continue;

		for (int i = 0; i < adj[cur.node].size(); i++)
		{
			int nextNode = adj[cur.node][i].first;
			int nextDist = adj[cur.node][i].second + cur.dist;

			if (dist[nextNode] > nextDist)
			{
				dist[nextNode] = nextDist;
				pq.push(Node(nextNode, nextDist));
			}
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N >> M;

	Init();
	
	vector<vector<pair<int,int>>> adj(N+1);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });		
	}

	int start, end;
	cin >> start >> end;

	dijkstra(start, end, adj);

	cout << dist[end];
}