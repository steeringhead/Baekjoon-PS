#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


map<string, double> m1;

void Setting()
{
	m1.insert({ "A+", 4.3 });
	m1.insert({ "A0", 4.0 });
	m1.insert({ "A-", 3.7 });
	m1.insert({ "B+", 3.3 });
	m1.insert({ "B0", 3.0 });
	m1.insert({ "B-", 2.7 });
	m1.insert({ "C+", 2.3 });
	m1.insert({ "C0", 2.0 });
	m1.insert({ "C-", 1.7 });
	m1.insert({ "D+", 1.3 });
	m1.insert({ "D0", 1.0 });
	m1.insert({ "D-", 0.7 });
	m1.insert({ "F", 0.0 });
}

int main()
{
	Setting();
	
	string s;
	cin >> s;

	cout << fixed;
	cout.precision(1);

	cout << m1[s];
}
