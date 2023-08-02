#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 129

using namespace std;

int map[MAX][MAX];
int blueCnt = 0;
int whiteCnt = 0;

void Check(int size, int xPos , int yPos)
{
	int tmp = map[xPos][yPos];
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

	if (flag == true)
	{
		if (tmp == 1)
			blueCnt++;
		else
			whiteCnt++;
	}

	else
	{
		Check(size / 2, xPos, yPos);
		Check(size / 2, xPos + size/2, yPos);
		Check(size / 2, xPos , yPos + size/2);
		Check(size / 2, xPos + size / 2, yPos + size / 2);
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	Check(N, 1, 1);

	cout << whiteCnt << '\n';
	cout << blueCnt;

}