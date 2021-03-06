#include <bits/stdc++.h>
using namespace std;
// number of rotations is equal to position of min element so first find min element

int findMin(vector<int>& nums) {
	int n = nums.size();
	//if already sorted 0 rotaions
	if (nums[0] <= nums[n - 1]) {
		return nums[0];
	}
	int i = 0;
	int j = n - 1;
	int mid;
	int pivot = -1;
	while (i <= j) {
		//sorted subpart
		if (nums[i] <= nums[j]) {
			pivot = i;
			break;
		}
		mid = i + (j - i) / 2;
		// min if element at both sides are small
		if (nums[mid] < nums[(mid - 1 + n) % n] && nums[mid] < nums[(mid + 1) % n]) {
			pivot = mid;
			break;
		}
		// go towards unsorted part
		// mid element > intital element then go to right side as left is sorted
		else if (nums[mid] > nums[j]) {
			i = mid + 1;
		}
		// mid element < end element then go to left side as right is sorted
		else if (nums[mid] < nums[i]) {
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

