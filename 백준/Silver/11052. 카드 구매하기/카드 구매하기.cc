#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[1001];
int card[1001];


int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> card[i];
	}

	dp[1] = card[1];
	for (int i = 2; i <= N; i++)
	{
		dp[i] = card[i];
		for (int j = 1; j <= i / 2; j++)
		{
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}

	cout << dp[N];

	//dp[2] ? card[2] 와 dp[1]+d[1]
	//dp[3] ? card[3] 와 dp[1]+dp[2]
	//dp[4] ? card[4] 와 dp[1]+dp[3] 혹은 dp[2]+dp[2]
	//dp[5] ? card[5] 와 dp[1]+dp[4] 혹은 dp[2] +dp[3]
	//dp[6] ? card[6] 와 dp[1]+dp[5] dp[2]+dp[4] dp[3]+dp[3]
}