#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Vector로 풀면 쉬우니까, vector한번 다른풀이 한번

const int MAX = 100000;
int arr[MAX];

int main() 
{
	int total = 0;
	int now = 0;
	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 0)
		{
			total -= arr[now];
			arr[now] = 0;
			now--;
		}
		else
		{
			arr[++now] = tmp;
			total += tmp;
		}
	}

	cout << total;
}