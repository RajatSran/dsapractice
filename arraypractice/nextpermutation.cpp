#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {

	int n = nums.size();
	if (n <= 1) {
		return;
	}
	int i, j;
	for (i = n - 2; i >= 0; --i)
	{
		if (nums[i] < nums[i + 1]) {
			break;
		}
	}
	if (i < 0) {
		reverse(nums.begin(), nums.end());
	} else {
		for (j = n - 1; j > i; j--) {
			if (nums[j] > nums[i]) {
				break;
			}
		}
		swap(nums[i], nums[j]);
		reverse(nums.begin() + i + 1, nums.end());
	}

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	nextPermutation(arr);
	for (int x : arr) {
		cout << x;
	}

}