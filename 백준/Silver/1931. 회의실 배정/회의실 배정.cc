#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Data
{
	int start;
	int end;
	Data(int a, int b) {
		start = a;
		end = b;
	}

	bool operator<(const Data& data) const {
		return end != data.end ? end < data.end : start < data.start;
	}
	
};

vector<Data> dataList;

int main() {
	int N;
	cin >> N;

	
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		Data tmp(a, b);
		dataList.push_back(tmp);
	}
	
	sort(dataList.begin(), dataList.end());

	int chkEnd = dataList[0].end;
	int chkIdx = 1;
	int totalNum = 1;

	while (chkIdx < N) {
		if (dataList[chkIdx].start >= chkEnd) {
			chkEnd = dataList[chkIdx].end;
			totalNum++;
            chkIdx++;
		}
		else {
			chkIdx++;
		}
	}

	cout << totalNum << '\n';
}