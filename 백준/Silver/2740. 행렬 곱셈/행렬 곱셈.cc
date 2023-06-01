#include <iostream>

using namespace std;

const int MAX_INPUT = 101;

int NM[MAX_INPUT][MAX_INPUT];
int MK[MAX_INPUT][MAX_INPUT];
int temp[MAX_INPUT];
int N, M, K;

void calc(int n) {


	while (true) {
		if (n > N) break;

		for (int i = 1; i <= M; i++) {
			temp[i] = NM[n][i];
		}

		for (int i = 1; i <= K; i++) {
			int tmp = 0;
			for (int j = 1; j <= M; j++) {				
				tmp += temp[j] * MK[i][j];
			}
			cout << tmp << " ";
		}

		cout << "\n";
		n++;
	}
	
	return;
}

int main() {
	

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> NM[i][j];
		}
	}

	cin >> M >> K;
	
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= K; j++) {
			cin >> MK[j][i];
		}
	}

	calc(1);	

}