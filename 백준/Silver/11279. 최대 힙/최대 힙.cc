#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
public:
	
	int size = 0;
	vector<int> v;
	
	MaxHeap()
	{
		v.push_back(0);
	}

	void push(int x)
	{
		size++;
		v.push_back(x);

		if (size == 1)
			return;

		int current = size;
		while (true)
		{
			int parent = current / 2;

			if (parent == 0)
				return;

			if (v[parent] < v[current])
			{
				int tmp = v[parent];
				v[parent] = v[current];
				v[current] = tmp;
				current = parent;
			}
			else
				break;
		}
	}

	void pop()
	{
		if (size == 0)
		{
			cout << 0 << '\n';
			return;
		}

		cout << v[1] << '\n';
		v[1] = v[size];
		size--;
		v.pop_back();
		int current = 1;

		while (true)
		{
			int cmp, index;
			int left = current * 2;
			int right = current * 2 + 1;
			if (left > size && right > size)
				return;
			else if (left <= size && right > size)
			{
				cmp = v[left];
				index = left;
			}
			else
			{
				cmp = (v[left] > v[right]) ? v[left] : v[right];
				index = (v[left] > v[right]) ? left : right;
			}

			if (v[current] < cmp)
			{
				int tmp = v[current];
				v[current] = cmp;
				v[index] = tmp;
				current = index;
			}

			else
				break;
		}
	}
};



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;

	MaxHeap heap;
	
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;

		if (tmp == 0)
			heap.pop();
		else
			heap.push(tmp);
	}
}