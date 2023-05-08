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
	int totalNum = 1;

	for (int i = 1; i < N; i++) {
		if (dataList[i].start >= chkEnd) {
			chkEnd = dataList[i].end;
			totalNum++;
		}		
	}

	cout << totalNum << '\n';
}