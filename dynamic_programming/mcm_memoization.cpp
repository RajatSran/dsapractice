#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];
int MatrixChainOrder(vector<int> arr, int i, int j) {
	//start and end
	if (i >= j) {
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	int mini = INT_MAX;
	int temp;
	for (int k = i; k <= j - 1; ++k)
	{
		temp = MatrixChainOrder(arr, i, k) + MatrixChainOrder(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		if (temp < mini)
		{
			mini = temp;
		}
	}
	dp[i][j] = mini;
	return dp[i][j];
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> arr = { 1, 2, 3, 4, 3 };
	memset(dp, -1, sizeof dp);
	cout << "Minimum number of multiplications is "
	     << MatrixChainOrder(arr, 1, arr.size() - 1);

}