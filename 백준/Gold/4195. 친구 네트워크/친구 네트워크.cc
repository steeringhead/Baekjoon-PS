#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int maxInput = 200001;
map<string, int> m;

int parent[maxInput];
int friendNum[maxInput];


int findParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = findParent(parent[x]);
}

void unionNode(int a, int b) {
	int aP = findParent(a);
	int bP = findParent(b);
	if (aP > bP) {
		parent[aP] = bP;
		friendNum[bP] += friendNum[aP];
	}
	else if (aP < bP) {
		parent[bP] = aP;
		friendNum[aP] += friendNum[bP];
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testCase, total;
	cin >> testCase;
	string str1, str2;
	map<string, int> ::iterator it;

	for (int i = 0; i < testCase; i++) {

		m.clear();
		cin >> total;

		
		for (int i = 0; i < maxInput; i++) {
			parent[i] = i;
			friendNum[i] = 1;
		}
		int a, b;
		int cnt = 0;
		for (int i = 0; i < total; i++) {
			cin >> str1 >> str2;
			it = m.find(str1);
			if (it == m.end()) {
				m[str1] = ++cnt;
				a = cnt;
			}
			else {
				a = it->second;
			}

			it = m.find(str2);
			if (it == m.end()) {
				m[str2] = ++cnt;
				b = cnt;
			}
			else b = it->second;			

			unionNode(a, b);
			int chk = (findParent(a) < findParent(b)) ? findParent(a) : findParent(b);
			cout << friendNum[chk] << '\n';
		}
	}

	return 0;

}