#include <iostream>

using namespace std;

int mm[21][21][21];


int w(int a,int b,int c) {

	if (a <= 0 || b <= 0 || c <= 0) {
		mm[0][0][0] = 1;
		return mm[0][0][0];
	}
	else if (a > 20 || b > 20 || c > 20) {
		if (mm[20][20][20] != 0) return mm[20][20][20];
		else return mm[20][20][20] = w(20,20,20);
	}
	else if (a < b && b < c) {
		if (mm[a][b][c] != 0) return mm[a][b][c];
		else return mm[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		if (mm[a][b][c] != 0) return mm[a][b][c];
		else return mm[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}


int main() {	

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		
		cout << "w(" << a << ", " << b << ", " << c << ") " << "= " << w(a, b, c) << endl;
		
	}
	
	
}