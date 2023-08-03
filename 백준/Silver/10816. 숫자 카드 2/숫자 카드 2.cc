#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

//unordered_map 사용한 HashMap풀이


unordered_map<int, int> um;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N,M,tmp;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		um[tmp]++;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		cout << um[tmp] << " ";
	}

	
}