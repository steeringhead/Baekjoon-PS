#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


bool Check(int x)
{
	bool gap = true;
	vector<int> list;
	while (x > 0)
	{
		int tmp = x % 10;
		list.push_back(tmp);
		x = x / 10;
	}

	int tmp = list[1] - list[0];

	for (int i = 2; i < list.size(); i++)
	{
		if (tmp != list[i] - list[i - 1])
			gap = false;
	}

	return gap;
}

int N;

int main()
{
	cin >> N;

	int cnt = 0;
	
	for (int i=1;i<=N;i++)
	{
		if (i < 100)
		{
			cnt++;
		}
		else
		{
			if (Check(i))
				cnt++;
		}
		
	}
	
	cout << cnt;
}
