#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	bool checkAns = true;
	int cnt = 0;
	
	for (int i = 0; i < N; i++)
	{
		string s;	
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			char tmp = s[i];
			bool flag = false;
			checkAns = true;
			for (int j = i + 1; j < s.length(); j++)
			{
				if (s[j] != tmp)
					flag = true;
				
				if (flag == true && s[j] == tmp)
				{
					checkAns = false;
					break;
				}
			}
			if (checkAns == false)
				break;
		}

		if (checkAns == true)
			cnt++;
	}

	cout << cnt;
}