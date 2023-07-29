#include <iostream>
#include <string>
#include <vector>

using namespace std;

int recursion(string& tmp, int l, int r, int& a)
{
	a++;
	if (l >= r) return 1;
	else if (tmp[l] != tmp[r])
		return 0;
	else
	{
		return recursion(tmp, l + 1, r - 1, a);
	}
}

int palindrome(string& tmp, int& a)
{
	return recursion(tmp, 0, tmp.length()-1,a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
		
	for (int i = 0; i < N; i++)
	{
		int a = 0;
		string tmp;
		cin >> tmp;
		cout << palindrome(tmp, a) << " " << a << '\n';
	}
}