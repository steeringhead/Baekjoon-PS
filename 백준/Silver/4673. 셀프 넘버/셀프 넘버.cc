#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int res[10000];

void SelfNumber(string x)
{
	string tmp = x;

	while (stoi(tmp) < 10000)
	{
		int y = 0;

		for (int i = 0; i < tmp.length(); i++)
		{
			y += tmp[i] - '0';
		}
		y += stoi(tmp);
		res[y] = 1;
		tmp = to_string(y);		
	}
}

int main()
{
	for (int i = 1; i < 10000; i++)
	{
		SelfNumber(to_string(i));
	}

	for (int i = 1; i < 10000; i++)
	{
		if (res[i] == 0)
			cout << i << '\n';
	}	
}
