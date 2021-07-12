#include<bits/stdc++.h>
using namespace std;

int maxn = INT_MIN;
int maxusingrec(vector<int> arr, int idx) {
	if (idx < 0) {
		return maxn;
	}
	maxn = maxusingrec(arr, idx - 1);
	return maxn = max(maxn, arr[idx]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "r", stdout);
#endif
	vector<int> arr = {1, 2, 5, 3, 6, 9, 3};
	cout << maxusingrec(arr, 6);

}
