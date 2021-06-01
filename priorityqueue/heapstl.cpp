#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << "maxheap" << endl;
	priority_queue<int, vector<int>> pq;//max heap
	pq.push(2);
	pq.push(3);
	pq.push(1);
	pq.push(5);
	cout << " top :" << pq.top() << endl;
	cout << " size :" << pq.size() << endl;
	pq.pop();
	cout << " top :" << pq.top() << endl;
	cout << " size :" << pq.size() << endl;

	cout << "minheap" << endl;
	priority_queue<int, vector<int>, greater<int>> pqm;//min heap
	pqm.push(2);
	pqm.push(3);
	pqm.push(1);
	pqm.push(5);
	cout << " top :" << pqm.top() << endl;
	cout << " size :" << pqm.size() << endl;
	pqm.pop();
	cout << " top :" << pqm.top() << endl;
	cout << " size :" << pqm.size() << endl;

}