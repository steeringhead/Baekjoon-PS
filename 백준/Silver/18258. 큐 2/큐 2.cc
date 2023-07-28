#include <iostream>
#include <string>
#include <vector>

using namespace std;

//QUEUE 구현

class Queue
{
	int capacity;
	int* arr;
	int Fptr;
	int Bptr;
	int currentSize;

public:
	Queue(int initSize) 
	{
		currentSize = 0;
		capacity = initSize * 2;
		arr = new int[capacity];
		Fptr = 0;
		Bptr = 0;
		
	}

	~Queue()
	{
		delete[] arr;
	}
	

	void push(int val)
	{
		//if (currentSize == capacity)
		//	resize();
		arr[Bptr++] = val;
		currentSize++;
	}

	int pop()
	{
		if (currentSize == 0)
			return -1;
		else
		{
			currentSize--;
			return arr[Fptr++];
		}
	}

	int size()
	{
		return currentSize;
	}

	int empty()
	{
		if (currentSize == 0)
			return 1;
		else
			return 0;
	}

	int front()
	{
		if (currentSize == 0)
			return -1;
		else
		{
			return arr[Fptr];
		}
	}

	int back()
	{
		if (currentSize == 0)
			return -1;
		else
		{
			return arr[Bptr - 1];
		}
	}
	
	//void resize()
	//{
	//	capacity *= 2;
	//	int* newArr = new int[capacity];
	//	for (int i = 0; i < currentSize; i++)
	//	{
	//		newArr[i] = arr[Fptr++];
	//	}
	//	Fptr = 0;
	//	Bptr = 0;
	//	delete[] arr;
	//	arr = newArr;
	//	
	//}
};


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	Queue Q(10000000);
	string str;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push")
		{
			int tmp;
			cin >> tmp;
			Q.push(tmp);
		}
		else if (str == "front")
		{
			cout << Q.front() << '\n';
		}
		else if (str == "pop")
		{
			cout << Q.pop() << '\n';
		}
		else if (str == "size")
		{
			cout << Q.size() << '\n';
		}
		else if (str == "empty")
		{
			cout << Q.empty() << '\n';
		}
		else
		{
			cout << Q.back() << '\n';
		}
	}
	
}