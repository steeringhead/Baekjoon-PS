#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int sNum = 15746;
long long dp[1000001];



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	
	dp[1] = 1;
	dp[2] = 2;	
	
	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] % sNum + dp[i - 2] % sNum) % sNum;
	}

	cout << dp[N];

	
}