#include<bits/stdc++.h>
using namespace std;

int MatrixChainOrder(vector<int> arr, int i, int j) {
	//start and end
	if (i >= j) {
		return 0;
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
	return mini;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector <int>arr = { 1, 2, 3, 4, 3 };
	cout << "Minimum number of multiplications is "
	     << MatrixChainOrder(arr, 1, arr.size() - 1);

}