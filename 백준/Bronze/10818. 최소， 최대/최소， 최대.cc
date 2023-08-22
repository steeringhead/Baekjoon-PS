#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int tmp = v.size() - 1;
	cout << v[0] << " " << v[tmp];
}