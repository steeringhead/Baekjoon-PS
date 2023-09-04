#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

struct Node
{
	int x;
	int y;
	Node(int a, int b)
	{
		x = a;
		y = b;
	}

	bool operator<(const Node& other) const
	{
		if (x == other.x)
			return y < other.y;
		else
			return x < other.x;
	}
};

int main()
{
	int N;
	cin >> N;
	vector<Node> v;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(Node(a, b));
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].x << " " << v[i].y << '\n';
	}
}
