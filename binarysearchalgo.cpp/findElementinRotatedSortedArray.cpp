#include <bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> nums, int i, int j, int target) {
	int mid;
	while (i <= j) {
		mid = i + (j - i) / 2;
		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] > target) {
			j = mid - 1;
		} else {
			i = mid + 1;
		}
	}
	return -1;
}

int search(vector<int>& nums, int target) {

	int pivot = -1;
	int n = nums.size();
	if (nums[0] <= nums[n - 1]) {
		pivot = 0;
	}
	int i = 0;
	int j = n - 1;
	int mid;
	while (i <= j) {
		if (nums[i] <= nums[j]) {
			pivot = i;
			break;
		}
		mid = i + (j - i) / 2;
		if (nums[mid] < nums[(mid - 1 + n) % n] && nums[mid] < nums[(mid + 1) % n]) {
			pivot = mid;
			break;
		}
		else if (nums[mid] > nums[j]) {
			i = mid + 1;
		}
		else if (nums[mid] < nums[i]) {
			j = mid - 1;
		}
	}

	int a = binarysearch(nums, 0, pivot - 1, target);
	int b = binarysearch(nums, pivot, n - 1, target);
	if (a != -1) {
		return a;
	} else if (b != -1) {
		return b;
	} else {
		return -1;
	}

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> x = { 8, 10, 12, -1, 2, 3 };


	cout << search(x, 2);
	return 0;
}

