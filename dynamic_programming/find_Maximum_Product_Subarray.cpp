// C++ program to find Maximum Product Subarray
#include <bits/stdc++.h>
using namespace std;


int maxSubarrayProduct(int nums[], int n)
{

	if (n == 0) {
		return 0;
	}

	int maxVal[n];
	int minVal[n];

	maxVal[0] = nums[0];
	minVal[0] = nums[0];

	for (int i = 1; i < n; i++) {
		maxVal[i] = max(maxVal[i - 1] * nums[i], max(minVal[i - 1] * nums[i], nums[i]));
		minVal[i] = min(maxVal[i - 1] * nums[i], min(minVal[i - 1] * nums[i], nums[i]));
	}

	int ans = INT_MIN;
	for (int num : maxVal) {
		ans = max(ans, num);
	}
	return ans;

}

// Driver code
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int arr[] = { -2 , -1, 1, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum Sub array product is "
	     << maxSubarrayProduct(arr, n);
	return 0;
}

// This is code is contributed by rathbhupendra

