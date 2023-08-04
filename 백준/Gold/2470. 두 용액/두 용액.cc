#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 100001

// 양수면 내리고 음수면 올리고
struct Node
{
	int x;
	int y;
	int sub;
	Node(int a, int b, int c)
	{
		x = a;
		y = b;
		sub = c;
	}

	bool operator<(const Node& other) const
	{
		return sub < other.sub;
	}
};

int numList[MAX];
vector<Node> v;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> numList[i];
	}

	sort(numList, numList + N);

	int l = 0, r = N - 1;

	while (l < r)
	{
		int tmp = numList[l] + numList[r];
		if (tmp < 0)
		{
			v.push_back(Node(numList[l], numList[r], tmp * -1));
			l++;
		}

		else
		{
			v.push_back(Node(numList[l], numList[r], tmp));
			r--;
		}	
		
	}

	sort(v.begin(), v.end());
	
	cout << v[0].x << " " << v[0].y;

}