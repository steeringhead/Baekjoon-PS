#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
	string s;
	cin >> s;
	
	vector<int> numList;

	for (int i = 0; i < s.length(); i++)
	{
		numList.push_back(s[i] - '0');
	}

	sort(numList.rbegin(), numList.rend());

	string res ="";
	
	for (int i = 0; i < numList.size(); i++)
	{
		string tmp = to_string(numList[i]);
		res += tmp;
	}

	cout << res;
}