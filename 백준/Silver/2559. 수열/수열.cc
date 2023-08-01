#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 100001;
int numList[MAX];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N ,K;
	cin >> N >> K;

	int init = 0;
	int MAX;

	for (int i = 1; i <= N; i++)
	{
		cin >> numList[i];
		if (i <= K)
			init += numList[i];
	}

	MAX = init;

	for (int i = 2; i <= N-K+1; i++)
	{		

		init = init - numList[i - 1] + numList[i + K - 1];
		if (init > MAX)
			MAX = init;
	}

	cout << MAX;
	
}