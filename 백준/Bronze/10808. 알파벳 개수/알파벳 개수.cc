#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string s;
int cnt[26];

int main()
{
	cin >> s;
	
	for (int i = 0; i < s.length(); i++)
	{
		int tmp = s[i] - 'a';
		cnt[tmp]++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << cnt[i] << " ";
	}
}
