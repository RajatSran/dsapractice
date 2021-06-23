#include<iostream>
using namespace std;

class StackUsingArray {
	int *data;
	int nextIndex;
	int capacity;
public:
	StackUsingArray(int totalSize) {
		data = new int[totalSize];
		nextIndex = 0;
		capacity = totalSize;
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
			cout << "stack is full";
			return;
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
			cout << "stack is enmpty";
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
	StackUsingArray s(4);
	s.insert(10);
	cout << s.top();

}