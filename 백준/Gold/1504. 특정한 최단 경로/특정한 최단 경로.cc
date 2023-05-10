#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxN = 801;
const int maxDistance = 100000000;


struct node {
	int dest;
	long long cost;
	node(int a, long long b) {
		dest = a;
		cost = b;
	}
	bool operator<(const node& other) const {
		return cost > other.cost;
	}
};

vector<node> info[maxN];

long long dijkstra(int start, int end, vector<long long> distArr) {
	if (start == end) return 0;
	priority_queue<node> pq;
	pq.push(node(start, 0));


	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		
		for (int i = 0; i < info[cur.dest].size(); i++) {
			int nodedst = info[cur.dest][i].dest;
			long long distance = info[cur.dest][i].cost + cur.cost;
			if (distance < distArr[nodedst]) {
				distArr[nodedst] = distance;
				pq.push(node(nodedst, distance));
			}
		}
	}

	return distArr[end];
}

int main() {
	int N, E;
	cin >> N >> E;


	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		info[a].push_back(node(b, c));
		info[b].push_back(node(a, c));
	}

	int endPoint[2] = { 0,0 };
	cin >> endPoint[0] >> endPoint[1];

	vector<long long> dist(maxN);
	for (int i = 1; i <= N; i++) {
		dist[i] = maxDistance;
	}

	long long sub1 = dijkstra(1, endPoint[0], dist) + dijkstra(endPoint[0], endPoint[1], dist) + dijkstra(endPoint[1], N, dist);
	long long sub2 = dijkstra(1, endPoint[1], dist) + dijkstra(endPoint[1], endPoint[0], dist) + dijkstra(endPoint[0], N, dist);


	if (sub1 >= maxDistance && sub2 >= maxDistance) cout << -1;
	else {
		if (sub1 > sub2) cout << sub2;
		else cout << sub1;
	}
}