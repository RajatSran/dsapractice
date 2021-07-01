#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
	if (x == 0)
		return 0;
	int left = 1, right = INT_MAX;
	while (true) {
		int mid = left + (right - left) / 2;
		if (mid > x / mid) {
			right = mid - 1;
		} else {
			if (mid + 1 > x / (mid + 1))
				return mid;
			left = mid + 1;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << mySqrt(144);
}