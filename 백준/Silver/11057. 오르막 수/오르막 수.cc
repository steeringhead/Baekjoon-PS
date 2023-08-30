#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[1001][10]; //[N자리수][맨앞자리숫자]

// 1 1 1 1 1 1 1 1 1 1
// 10 9 8 7 6 5 4 3 2 1
// 55

int main()
{
	for (int i = 0; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			long long sum = 0;
			for (int k = j; k <= 9; k++)
			{
				sum += (dp[i - 1][k]) % 10007;
			}
			dp[i][j] = sum % 10007;
		}
	}
		
	int N;
	cin >> N;
	long long res = 0;
	for (int i = 0; i <= 9; i++)
	{
		res += dp[N][i];
	}
	cout << res % 10007;
}
