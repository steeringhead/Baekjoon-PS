#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string a, b;
int dp[1001][1001];


int main()
{
	cin >> a >> b;

	int len1 = a.length();
	int len2 = b.length();

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (a[i-1] == b[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	cout << dp[len1][len2];
	
}