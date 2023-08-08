#include <iostream>
#include <string>

using namespace std;

//나눗셈을 사용해서 int형으로 받고 뒤집는 방법도 있겠지만, 문자열을 사용해보자.
//몰랐던 사실 -> string이 숫자로만 이루어져있다면 대소비교가 가능하다 ! ! !

string a,b;

int main()
{
	cin >> a >> b;
	
	string ra, rb;
	for (int i = 2; i >= 0; i--)
	{
		ra += a[i];
		rb += b[i];
	}

	cout << max(ra, rb);
}