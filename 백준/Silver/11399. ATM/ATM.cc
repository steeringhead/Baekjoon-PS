#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int list[MAX];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> list[i];
	}

	sort(list,list + N + 1);

	for (int i = 1; i <= N; i++)
	{
		list[i] = list[i - 1] + list[i];
	}
	
	int sum = 0;

	for (int i = 1; i <= N; i++)
	{
		sum += list[i];
	}

	cout << sum;
}