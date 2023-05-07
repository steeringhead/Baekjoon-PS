#include <iostream>

using namespace std;

const int maxInput = 301;

int mm[maxInput];
int score[maxInput];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> score[i];
	}

	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			mm[i] = score[1];
		}

		if (i == 2) {
			mm[i] = score[1] + score[2];
		}

		if (i > 2) {
			int sub1, sub2;
			sub1 = score[i] + mm[i - 2];
			sub2 = score[i] + score[i - 1] + mm[i - 3];
			if (sub1 > sub2) {
				mm[i] = sub1;
			}
			else {
				mm[i] = sub2;
			}
		}
	}

	cout << mm[N] << '\n';

}