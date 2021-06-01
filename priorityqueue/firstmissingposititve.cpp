#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
Given an unsorted integer array nums, find the smallest missing positive integer.
*/
int smallestMissingPositive(vector<int>& nums) {
	int n = nums.size();
	vector<int> mark;
	mark.assign(n, 0);

	if (n == 0) {
		return 1;
	}

	for (int i = 0; i < n; i++) {
		if (nums[i] > 0 && nums[i] < n + 1) {
			mark[nums[i] - 1] = 1;
		}
	}
	int missing = n + 1;
	for (int i = 0; i < n; i++) {
		if (mark[i] == 0) {
			missing = i + 1;
			break;
		}
	}
	return missing;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		nums.push_back(a);
	}
	cout << smallestMissingPositive(nums);

}