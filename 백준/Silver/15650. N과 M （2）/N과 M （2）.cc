#include <iostream>
#include <vector>

using namespace std;

const int maxInput = 9;

bool visited[maxInput] = { false, };
vector<int> temp;
int N, M;

void DFS(int cnt , int cur) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << temp[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = cur; i <= N; i++) {
		
		if (visited[i] == false) {
			visited[i] = true;
			temp.push_back(i);
			DFS(cnt + 1, i);
			visited[i] = false;
			temp.pop_back();
		}
		
	}
}

int main() {
	cin >> N >> M;	
	DFS(0, 1);
}