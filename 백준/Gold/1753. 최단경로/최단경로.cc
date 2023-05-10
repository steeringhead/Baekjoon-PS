#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxV = 20001;
const int maxDistance = 1000000000;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}


void dijkstra(int start, vector<vector<pair<int, int>>> vec , vector<int>& dist) {
	priority_queue<pair<int, int>,vector<pair<int,int>>,decltype(&cmp)> pq(&cmp);
	dist[start] = 0;	

	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		auto cur = pq.top();		
		pq.pop();

		if (dist[cur.second] < cur.first) continue;

		for (int i = 0; i < vec[cur.second].size(); i++) {
			
			int node = vec[cur.second][i].first;
			int distance = vec[cur.second][i].second + cur.first;
			if (distance < dist[node]) {
				dist[node] = distance;
				pq.push(make_pair(distance, node));
			}

		}
	}
	
}

int main() {
	int start;
	int V, E;

	cin >> V >> E;
	cin >> start;

	vector<vector<pair<int, int>>> adjacent(V+1);
	
	vector<int> dist(V + 1);
	
	for (int i = 1; i <= V; i++) {
		dist[i] = maxDistance;
	}
	

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adjacent[a].push_back(make_pair(b, c));
	}

	dijkstra(start,adjacent,dist);

	for (int i = 1; i <= V; i++) {
		if (dist[i] != maxDistance) cout << dist[i] << '\n';
		else cout << "INF" << '\n';
	}
}