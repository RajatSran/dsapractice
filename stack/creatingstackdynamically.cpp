#include<iostream>
using namespace std;

class StackUsingArray {
	int *data;//as we don't know the size we are creating it dynamically
	int nextIndex;
	int capacity;
public:
	StackUsingArray() {
		data = new int[4];
		nextIndex = 0;
		capacity = 4;
	}
	int size() {
		return capacity;
	}
	bool isEmpty() {
		return nextIndex == 0;
	}

	void insert(int element) {
		if (nextIndex == capacity)
		{
			int *newData = new int[2 * capacity];
			for (int i = 0; i < capacity; ++i)
			{
				newData[i] = data[i];
			}
			capacity *= 2;
			delete [] data;
			data = newData;
		}

		data[nextIndex] = element;
		nextIndex++;
	}

	int pop() {
		if (nextIndex == 0)
		{
			cout << "stack is enmpty";
			return INT_MIN;
		}
		nextIndex--;
		return data[nextIndex];
	}
	int top() {
		if (nextIndex == 0)
		{
			cout << "stack is empty";
			return INT_MIN;
		}
		return data[nextIndex - 1];
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	StackUsingArray s;
	s.insert(10);
	cout << s.top() << endl;
	s.insert(20);
	s.insert(30);
	cout << s.size() << endl;
	s.insert(40);
	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
}