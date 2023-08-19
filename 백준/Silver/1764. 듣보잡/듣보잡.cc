#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int N,M;
map<string, bool> list;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		list.insert({ s,true });
	}

	vector<string> v;

	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if (list[s])
			v.push_back(s);
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
	
}
