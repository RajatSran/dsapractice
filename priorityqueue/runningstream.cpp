/* median of running stream */

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

priority_queue<int, vector<int>> maxpq;
priority_queue<int, vector<int>, greater<int>> minpq;

void insert(int n) {
	if (maxpq.size() == minpq.size())
	{
		if (maxpq.size() == 0)
		{
			maxpq.push(n);
			return;
		}

		if (n < maxpq.top()) {
			minpq.push(n);
		}

	} else {
		//maxheap>minheap
		//minheap>maxheap
		if ( maxpq.top() > minpq.top())
		{
			if (maxpq.top() <= n)
			{
				minpq.push(n);
			}
			else {
				int temp = maxpq.top();
				maxpq.pop();
				maxpq.push(n);
				minpq.push(temp);
			}
		} else {
			if (minpq.top() >= n)
			{
				maxpq.push(n);
			} else {
				int temp = minpq.top();
				minpq.pop();
				minpq.push(n);
				maxpq.push(temp);
			}
		}
	}
}

double findMedian() {
	if (minpq.size() == maxpq.size())
	{
		return (double)(minpq.top() + maxpq.top()) / 2;
	} else if (minpq.size() > maxpq.size()) {
		return minpq.top();
	} else {
		return maxpq.top();
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	insert(12);
	cout << findMedian() << endl;
	insert(12);
	cout << findMedian() << endl;
	insert(3);
	cout << findMedian() << endl;
	insert(4);
	cout << findMedian() << endl;
}