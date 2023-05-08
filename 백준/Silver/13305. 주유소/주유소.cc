#include <iostream>

using namespace std;

const int maxInput = 100001;

int dist[maxInput];
int price[maxInput];


int main() {
	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		int tmp;
		cin >> tmp;
		dist[i] = tmp;
	}

	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		price[i] = tmp;
	}

	int curPrice = price[1];
	int curIdx = 2;
	long long total = 0;

	while (curIdx <= N) {
		if (curPrice >= price[curIdx]) {
			total += curPrice * dist[curIdx];
			curPrice = price[curIdx];
			curIdx++;			
		}
		else {
			total += curPrice * dist[curIdx];
			curIdx++;
		}
	}
	
	cout << total;
}