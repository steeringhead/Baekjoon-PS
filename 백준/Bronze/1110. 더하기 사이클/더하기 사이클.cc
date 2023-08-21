#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void PlusCycle(string num)
{
	string tmp = num;
	int cnt = 0;
	while (true)
	{
		if (stoi(tmp) < 10)
		{
			tmp = "0" + tmp;
		}
		
		int tmp2 = tmp[0] - '0' + tmp[1] - '0';
		
		string newStr = tmp[1] + to_string(tmp2 % 10);
		int check = stoi(newStr);

		if (check == stoi(num))
		{
			cnt++;
			break;
		}
		else
		{
			cnt++;
			tmp = to_string(check);
		}
	}
	cout << cnt;
}

int main()
{
	string N;
	cin >> N;
	
	PlusCycle(N);

}