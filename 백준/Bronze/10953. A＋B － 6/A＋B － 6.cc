#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;


int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		cout << tmp[0] - '0' + tmp[2] - '0' << '\n';
	}
}