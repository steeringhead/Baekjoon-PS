#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;


void check(string& s)
{
	vector<char> v;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ')')
		{
			if (v.empty())
			{
				cout << "NO" << '\n';
				return;
			}
			else
			{
				v.pop_back();
			}
		}
		else
		{
			v.push_back(s[i]);
		}
	}

	if (v.empty() == false)
	{
		cout << "NO" << '\n';
		return;
	}
	else
	{
		cout << "YES" << '\n';
		return;

	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		check(s);
	}
}
