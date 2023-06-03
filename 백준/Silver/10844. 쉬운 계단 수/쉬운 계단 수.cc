#include <iostream>

using namespace std;

const int maxInput = 101;
const int ansChk = 1000000000;

int dp[10][maxInput];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	// case 3개로 나눠서 dp에 담기

	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++) {
		dp[i][1] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {

			if (j == 0) {
				// 0으로 끝나는건 앞에가 1인 경우만 가능함
				dp[j][i] = dp[1][i - 1];
			}

			else if (j == 9) {
				// 9로 끝나는 계단수는 앞에가 8일 때만 생성이 가능함 7이하도 안되고 0도 안되니까
				dp[j][i] = dp[8][i - 1];
			}
			
			else {
				//나머지는 2개씩 나올수 있음.
				dp[j][i] += dp[j - 1][i - 1];
				dp[j][i] += dp[j + 1][i - 1];
			}

			dp[j][i] %= ansChk;
		}
	}
	int cnt = 0;
	
	for (int i = 0; i <= 9; i++) {
		cnt += dp[i][N];
		cnt %= ansChk;
	}

	cout << cnt;
}