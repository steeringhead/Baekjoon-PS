#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int NL[500000];
int ML[500000];

//logN 이분탐색으로 하면 시간초과가 날일이없음

bool BinarySearch(int x)
{
	int left = 0;
	int right = N-1;	

	while (left <= right)
	{
		int cur = (left + right) / 2;

		if (NL[cur] == x)
			return true;

		if (NL[cur] < x)
		{
			left = cur + 1;
		}
		else
		{
			right = cur - 1;
		}
	}

	return false;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> NL[i];
	}

	sort(NL, NL + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> ML[i];		
	}

	for (int i = 0; i < M; i++)
	{
		bool tmp = BinarySearch(ML[i]);
		if (tmp)
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	
}