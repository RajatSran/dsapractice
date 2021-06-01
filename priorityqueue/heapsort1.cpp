#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	priority_queue<int, vector<int>> pq;
	pq.push(2);
	pq.push(3);
	pq.push(1);
	pq.push(5);
	cout << pq.top() << endl;
	cout << pq.size() << endl;
	pq.pop();
	cout << pq.top() << endl;
	cout << pq.size() << endl;

}