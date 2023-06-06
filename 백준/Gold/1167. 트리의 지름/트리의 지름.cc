#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxInput = 100001;

struct Node {
	int node;
	int dist;
	Node(int n, int d) {
		node = n;
		dist = d;
	}
	bool operator<(Node& other) {
		return dist > other.dist;
	}
};

vector<Node> adj[maxInput];
vector<Node> tmp;
int inputInfo[maxInput];
bool visited[maxInput];

void dfs(int v, int d) {
	if (visited[v] == true) {		
		return;
	}
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		int nextNode = adj[v][i].node;
		if (visited[nextNode] == true) {
			tmp.push_back(Node(v, d));			
			continue;
		}
		int nextDist = adj[v][i].dist;		
		dfs(nextNode, nextDist + d);
	}
}

int main() {
	int V;
	cin >> V;
	
	for (int i = 1; i <= V; i++) {
		int from, to, dist;
		cin >> from;
		while (true) {
			cin >> to;
			if (to == -1) {
				break;
			}
			cin >> dist;
			adj[from].push_back(Node(to, dist));
		}
	}

	//dfs두번 돌리면 됨.
	dfs(1, 0);
	sort(tmp.begin(), tmp.end());
	int next = tmp[0].node;
	tmp.clear();
	fill_n(visited, maxInput, false);

	dfs(next, 0);
	sort(tmp.begin(), tmp.end());

	cout << tmp[0].dist;

}