#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;

int arr[MAX_N + 1];
int dp[MAX_N + 1];

//포도주 관련 점화식을 세우자.


int main() {

	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];		
	}

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	
	
	for (int i = 3; i <= N; i++) {
		int temp[3] = {0,0,0};
		temp[0] = dp[i - 3] + arr[i - 1] + arr[i];
		temp[1] = dp[i - 2] + arr[i];
		temp[2] = dp[i - 1];
		sort(temp, temp + 3);
		dp[i] = temp[2];
	}

	cout << dp[N] << "\n";

}