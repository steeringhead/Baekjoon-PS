#include <iostream>
#include <string>

using namespace std;
//a = 97

int info[26];

int main()
{
	for (int i = 0; i < 26; i++)
	{
		info[i] = -1;
	}

	string s;
	cin >> s;
	
	for (int i = 0; i < s.length(); i++)
	{
		int tmp = static_cast<int>(s[i]) - 97;
		if (info[tmp] == -1)
			info[tmp] = i;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << info[i] << " ";
	}
}