#include <iostream>
#include <vector>

using namespace std;

int info[1001];

int main()
{
	int N;
	cin >> N;

	
	info[1] = 1;
	info[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		info[i] = (info[i - 1] + info[i - 2])%10007;
	}

	
	cout << info[N];
}
