#include <iostream>
#include <string>

using namespace std;

int cntList[6];

int main()
{	
	int normal[6] = { 1,1,2,2,2,8 };

	for (int i = 0; i < 6; i++)
	{
		cin >> cntList[i];
		int tmp = normal[i] - cntList[i];
		cout << tmp << " ";
	}

}