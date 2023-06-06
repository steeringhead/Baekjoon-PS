#include <iostream>
#include <vector>

using namespace std;

const int maxInput = 27;

struct Node
{
	char left;
	char right;

	Node() {
		left = ' ';
		right = ' ';
	}

	Node(char a, char b) {
		left = a;
		right = b;
	}
};

Node arr[maxInput*2 + 2];

void preOrder(int s) {
	int idx = s;
	if (idx >= maxInput * 2 + 2 || static_cast<char>(idx+'A'-1) == '.') return;
	cout << static_cast<char>(idx+'A'-1);
	preOrder(arr[idx].left-'A'+1);
	preOrder(arr[idx].right-'A'+1);
}

void inOrder(int s) {
	int idx = s;
	if (idx >= maxInput * 2 + 2 || static_cast<char>(idx + 'A' - 1) == '.') return;
	inOrder(arr[idx].left - 'A' + 1);
	cout << static_cast<char>(idx + 'A' - 1);
	inOrder(arr[idx].right - 'A' + 1);
}

void postOrder(int s) {
	int idx = s;
	if (idx >= maxInput * 2 + 2 || static_cast<char>(idx + 'A' - 1) == '.') return;
	postOrder(arr[idx].left - 'A' + 1);
	postOrder(arr[idx].right - 'A' + 1);
	cout << static_cast<char>(idx + 'A' - 1);
}

int main() {

	int N;
	cin >> N;
	

	for (int i = 1; i <= N; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		int idx = a-'A'+1;
		Node tmp = Node(b, c);
		arr[idx] = tmp;
	}

	preOrder(1);
	cout << "\n";
	inOrder(1);
	cout << "\n";
	postOrder(1);
	cout << "\n";
}