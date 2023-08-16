#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
	string s;
	cin >> s;

	int cnt = 0;
	
	for (int i = 0; i < s.length(); i++)
	{
		if (cnt % 10 == 0 && cnt != 0)
		{
			cout << '\n';	
			
		}
		cout << s[i];
		cnt++;
	}
}