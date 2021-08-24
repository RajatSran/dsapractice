#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
	int i = nums.size() - 2, j = i + 2;
	while (i >= 0 && nums[i] >= nums[i + 1]) i--;
	if (i == -1) {
		reverse(begin(nums), end(nums));
		return;
	}
	while (nums[--j] <= nums[i]);
	swap(nums[i], nums[j]);
	sort(begin(nums) + i + 1, end(nums));
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

}