#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;



int N;
string s;
int res;

int Calculate(int a, int b, char op)
{
	int result = a;
	
	switch (op)
	{
	case '+': result += b; break;
	case '-': result -= b; break;
	case '*': result *= b; break;
	}

	return result;
}

void DFS(int idx, int cur)
{
	if (idx > N-1)
	{
		int tmp = max(cur, res);
		res = tmp;
		return;
	}

	char op = (idx == 0) ? '+' : s[idx - 1];

	//괄호해서 보내기
	if (idx + 2 < N) // 이러면 괄호가 가능. //1+2+3
	{
		int tmp = Calculate(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
		DFS(idx + 4, Calculate(cur, tmp, op));
	}


	//괄호 안해서 보내기
	DFS(idx + 2, Calculate(cur, s[idx] - '0', op));
}

int main()
{
	cin >> N;
	cin >> s;
	res = INT_MIN;

	DFS(0, 0);
	cout << res;
}