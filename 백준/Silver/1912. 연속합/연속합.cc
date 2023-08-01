#include <iostream>
#include <string>
#include <vector>

using namespace std;

//2차원 DP 만들어서 구간별로 값 넣어두고 답 도출할려했는데 입력값이 너무 커서 배열 생성안됌 -> 첫 번째 문제
//2중 for문 돌리면 시간초과 나오기때문에 어차피 안됌 -> 두 번째 문제
//결국 2차원 DP로 푸는문제가 아니라는것.


const int MAX = 100000;
int dp[MAX];
int input[MAX];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int total;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}

	dp[0] = input[0];
	total = dp[0];

	for (int i = 1; i < N; i++)
	{
		if (input[i] + dp[i - 1] > input[i])
		{
			dp[i] = input[i] + dp[i - 1];
			if (total < dp[i])
				total = dp[i];
		}

		else
		{
			dp[i] = input[i];
			if (total < dp[i])
				total = dp[i];
		}
	}

	if (N == 1)
	{
		cout << input[0];
		
	}
	else
		cout << total;

	
}