#include<bits/stdc++.h>#include<iostream>using namespace std;int laststone(priority_queue<int, vector<int>>pq) {	int n = pq.size();	while (n > 1) {		int max1 = pq.top();		pq.pop();		int max2 = pq.top();		pq.pop();		n -= 2;		int diff = max1 - max2;		if (diff > 0)		{			pq.push(diff);			n += 1;		}	}	if (n > 0) {		return pq.top();	}	return 0;}int main() {#ifndef ONLINE_JUDGE	freopen("input.txt", "r", stdin);	freopen("output.txt", "w", stdout);#endif	int n;	cin >> n;	priority_queue<int, vector<int>> pq;	for (int i = 0; i < n; ++i)	{		int a;		pq.push(n);	}	cout << laststone(pq);}