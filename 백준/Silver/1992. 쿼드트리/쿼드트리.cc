#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 64

using namespace std;

string map[MAX];

void Check(int size, int xPos , int yPos)
{
	char tmp = map[xPos][yPos];
	int flag = true;
	
	for (int i = xPos; i < xPos + size; i++)
	{
		for (int j = yPos; j < yPos + size; j++)
		{
			if (map[i][j] != tmp)
			{
				flag = false;
				break;
			}
			
		}
		if (flag == false)
			break;
	}

	if (flag == false)
	{		
		cout << '(';
		Check(size / 2, xPos, yPos);
		Check(size / 2, xPos, yPos + size / 2);
		Check(size / 2, xPos + size / 2, yPos);
		Check(size / 2, xPos + size / 2, yPos + size / 2);
		cout << ')';
	}
	else
	{		
		cout << tmp;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	Check(N, 0, 0);

}