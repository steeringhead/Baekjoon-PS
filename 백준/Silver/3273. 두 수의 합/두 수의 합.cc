#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_INPUT = 100001;

int list[MAX_INPUT];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N,X;
	
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	
	sort(list+1, list + N + 1);
	cin >> X;
	
	int cnt = 0;
	int p1 = 1, p2 = N;
	
	while (p1<p2) {
		int tmp = list[p1] + list[p2];
		if (tmp == X) {
			cnt++;
			p1++;
			p2--;
		}
		else if (tmp < X) {
			p1++;
		}
		else {
			p2--;
		}
	}

	cout << cnt << "\n";

}