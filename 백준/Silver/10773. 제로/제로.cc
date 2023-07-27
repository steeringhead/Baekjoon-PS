#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Vector로 풀면 쉬우니까, vector한번 다른풀이 한번

int main() 
{
	int K;
	cin >> K;
	vector<int> V;
	
	for (int i = 0; i < K; i++)
	{
		int tmp;
		cin >> tmp;

		if (tmp == 0)
		{
			V.pop_back();
		}
		else
			V.push_back(tmp);
	}

	int res = 0;
	for (int i = 0; i < V.size(); i++) {
		res += V[i];
	}

	cout << res;
}