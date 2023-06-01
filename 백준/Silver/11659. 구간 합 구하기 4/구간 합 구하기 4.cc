#include <iostream>

using namespace std;

const int MAX_INPUT = 100001;

int list[MAX_INPUT];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		list[i] = list[i - 1] + tmp;
	}

	for (int i = 0; i < M; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		cout << list[tmp2] - list[tmp1 - 1] << "\n";
	}
	
	
}