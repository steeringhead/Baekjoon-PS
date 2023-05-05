#include <iostream>
#include <vector>

using namespace std;

const int maxInput = 9;

bool visited[maxInput] = { false, };
int temp[maxInput] = { 0, };
int N, M;

void DFS(int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << temp[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			temp[cnt] = i;
			DFS(cnt + 1);
			visited[i] = false;
		}
		
	}
}

int main() {
	cin >> N >> M;	
	DFS(0);
}