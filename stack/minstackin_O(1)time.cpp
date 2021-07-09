#include<bits/stdc++.h>
#include<iostream>
using namespace std;

stack<int> minstack(vector<int> array) {
	stack<int> s;
	stack<int> ms;
	s.push(array[0]);
	ms.push(array[0]);
	for (int i = 1; i < array.size(); ++i)
	{
		if (s.top() >= array[i]) {
			ms.push(array[i]);
		} else {
			ms.push(s.top());
		}
		s.push(array[i]);
	}
	return ms;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> array = {8, 10, 6, 3, 7};
	stack<int> mins = minstack(array);
	while (!mins.empty()) {
		cout << mins.top() << " ";
		mins.pop();
	}
}