#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
	int N;
	cin >> N;

	

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		int total = 0;
		int cnt = 0;


		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'X')
			{
				cnt = 0;
			}
			else
			{
				cnt++;
				total += cnt;
			}
		}

		cout << total << '\n';
	}
	


	
}