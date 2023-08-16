#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



struct Node
{
	string s;
	Node(string s1)
	{
		s = s1;
	}

	bool operator<(const Node& other) const
	{
		if (s.length() == other.s.length()) {
			return s < other.s; 
		}
		else {
			return s.length() < other.s.length();
		}
	}

};

int N;
vector<Node> sV;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		sV.push_back(Node(s));
	}

	sort(sV.begin(), sV.end());
	
	string tmp ="";
	for (const Node& node : sV) {		
		if (tmp == node.s)
			continue;
		tmp = node.s;
		cout << node.s << endl;
	}

}