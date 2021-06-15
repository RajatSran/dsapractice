#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	int t[n];
	if (n <= 1) return 0;
	for (int i = 0; i < n; i++) {
		t[i] = 1;
	}
	int result = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				t[i] = max(t[i], 1 + t[j]);

			}
			result = max(t[i], result);
		}
	}
	// return result;
	if (result >= 3) {
		return true;
	} else {
		return false;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> x = {1, 2, 1, 3};

	cout << lengthOfLIS(x);
	return 0;
}