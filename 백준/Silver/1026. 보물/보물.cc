#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int An[50];
int Bn[50];

bool desc(int a, int b)
{
	return a > b;
}

int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> An[i];
	}

	sort(An, An + N);

	for (int i = 0; i < N; i++)
	{
		cin >> Bn[i];
	}

	sort(Bn, Bn + N, desc);
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum += An[i] * Bn[i];
	}

	cout << sum;

}