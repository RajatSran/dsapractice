#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i)
	{
		m[nums[i]]++;
	}
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;

	for (auto i : m)
	{
		minh.push({i.second, i.first});
		if (minh.size() > k)
		{
			minh.pop();
		}
	}

	vector<int> v;
	while (!minh.empty()) {
		v.push_back(minh.top().second);
		minh.pop();
	}
	return v;

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> nums;
	int n;
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		nums.push_back(a);
	}
	vector<int> result = topKFrequent(nums, k);
	for (int i : result) {
		cout << i << endl;
	}

}