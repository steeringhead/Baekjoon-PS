#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;

string s[5];

int main()
{
	int len = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> s[i];
		if (s[i].length() > len)
			len = s[i].length();
	}

	string tmp = "";

	int idx = 0;

	while (idx <= len-1)
	{
		for (int i = 0; i < 5; i++)
		{
			if (s[i].length() - 1 >= idx)
			{
				tmp += s[i][idx];
			}
			
		}
		cout << tmp;
		tmp = "";
		idx++;
	}
}