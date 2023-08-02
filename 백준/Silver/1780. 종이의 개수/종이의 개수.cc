#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>


using namespace std;


const int MAX = 3 * 3 * 3 * 3 * 3 * 3 * 3;
int map[MAX][MAX];
int zero = 0;
int minusOne = 0;
int one = 0;

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

	if (flag == false)
	{		
		Check(size / 3, xPos, yPos);
		Check(size / 3, xPos + size / 3, yPos);
		Check(size / 3, xPos + (size / 3)*2, yPos);

		Check(size / 3, xPos, yPos + size / 3);
		Check(size / 3, xPos + size / 3, yPos + size / 3);
		Check(size / 3, xPos + (size / 3)*2, yPos + size / 3);

		Check(size / 3, xPos, yPos + (size / 3) * 2);
		Check(size / 3, xPos + (size / 3) , yPos + (size / 3) * 2);
		Check(size / 3, xPos + (size / 3)*2, yPos + (size / 3) * 2);
	}
	else
	{		
		if (tmp == 0)
			zero++;
		else if (tmp == -1)
			minusOne++;
		else
			one++;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	Check(N, 0, 0);
	cout << minusOne << '\n';
	cout << zero << '\n';
	cout << one << '\n';

}