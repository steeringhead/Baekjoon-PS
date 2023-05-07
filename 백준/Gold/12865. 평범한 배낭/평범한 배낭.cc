#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 101;
const int maxM = 100001;

int mm[maxN][maxM];
int weight[maxN];
int value[maxN];



int main() {
	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		weight[i] = a;
		value[i] = b;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (j >= weight[i]) {
				mm[i][j] = max(mm[i - 1][j], mm[i - 1][j - weight[i]] + value[i]);
			}
			else {
				mm[i][j] = mm[i - 1][j];
			}
		}
	}

	cout << mm[N][M];

	
}