#include <bits/stdc++.h>
using namespace std;


int search(vector<int>& nums, int target) {
	//given sorted array
	int i = 0;
	int j = nums.size() - 1;
	int mid = j / 2;
	while (i <= j) {
		mid = i + (j - i) / 2;
		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] < target) {
			i = mid + 1;
		} else {
			j = mid - 1;
		}
	}
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> x = { -1, 2, 3 , 8, 10, 12};

	cout << search(x, 10);
	return 0;
}

