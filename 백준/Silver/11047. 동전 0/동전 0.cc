#include <iostream>

using namespace std;

const int maxN = 11;

int coinArr[maxN];

int main() {
	int N, K;
	cin >> N >> K;

	int output = 0;

	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		coinArr[i] = tmp;
	}
	
	for (int i = N; i > 0; i--) {
		if (K / coinArr[i] == 0) {
			continue;
		}
		else {
			output += K / coinArr[i];
			K = K % coinArr[i];			
		}
	}

	cout << output << '\n';
	
}