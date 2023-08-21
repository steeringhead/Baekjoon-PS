#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string s;

int main()
{
	cin >> s;
	
	int res = 0;
	bool flag = false;
	
	int idx = 0;
	
	string tmp = "";
	
	while (idx < s.length())
	{
		if (s[idx] != '-' && s[idx] != '+')
		{
			tmp += s[idx];			
		}
		
		if (s[idx] == '+' || s[idx] == '-' || idx == s.length() - 1)
		{
			if (flag == true)
			{
				res -= stoi(tmp);
				tmp = "";				
			}
			else
			{
				res += stoi(tmp);
				tmp = "";				
			}
		}

		if (s[idx] == '-')
		{
			flag = true;
		}

		idx++;
	}

	cout << res;
	
}