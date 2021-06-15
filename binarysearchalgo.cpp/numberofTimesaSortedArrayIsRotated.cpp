#include <bits/stdc++.h>
using namespace std;


int findMin(vector<int>& nums) {
	int n = nums.size();
	if (nums[0] <= nums[n - 1]) {
		return nums[0];
	}
	int i = 0;
	int j = n - 1;
	int mid;
	int pivot = -1;
	while (i <= j) {
		if (nums[i] <= nums[j]) {
			pivot = i;
			break;
		}
		mid = i + (j - i) / 2;
		if (nums[mid] < nums[(mid - 1 + n) % n] && nums[mid] < nums[(mid + 1) % n]) {
			pivot = mid;
			break;
		} else if (nums[mid] > nums[j]) {
			i = mid + 1;
		} else if (nums[mid] < nums[i]) {
			j = mid - 1;
		}
	}
	return nums[pivot];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> x = { 8, 10, 12, -1, 2, 3 };


	cout << findMin(x);
	return 0;
}

