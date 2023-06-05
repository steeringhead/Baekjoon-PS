#include<iostream>
#include<queue>

using namespace std;
const int INF = 100000000;
const int maxInput = 100001;

int dir[3] = {2, 1,-1 };
int totalSec[maxInput];

struct Pos {
	int pos;
	int sec;
	Pos(int a, int b) {
		pos = a;
		sec = b;
	}	
};

void searchBrother(int start, int end) {
	queue<Pos> Q;
	Q.push(Pos(start, 0));
	totalSec[start] = 0;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();		

		if (cur.pos == end) {
			cout << totalSec[cur.pos];
			return;
		}

		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				int newPos = cur.pos * dir[i];
				if (newPos >= maxInput || newPos < 0) continue;
				if (totalSec[newPos] > cur.sec) {
					totalSec[newPos] = cur.sec;
					Q.push(Pos(newPos, cur.sec));
				}
			}
			else {
				int newPos = cur.pos + dir[i];
				int newSec = cur.sec + 1;
				if (newPos >= maxInput || newPos < 0) continue;
				if (totalSec[newPos] > newSec) {
					totalSec[newPos] = newSec;
					Q.push(Pos(newPos, newSec));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	fill_n(totalSec, maxInput, INF);

	searchBrother(N, K);

}