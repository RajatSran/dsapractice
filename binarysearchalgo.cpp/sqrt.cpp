#include<bits/stdc++.h>
using namespace std;

double eps = 1e-6; //10^(-6)

//more precision more complexity
double SQR(double x) {
	if (x == 0) return 0;
	double lo = 1, hi = x, mid;
	while (hi - lo > eps) {
		mid = (hi + lo) / 2;
		if (mid * mid < x) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	return lo;
}

int mySqrt(int x)
{
	if (x == 0) return 0;
	int lo = 1, hi = x, mid;
	while (hi - lo >= 0 ) {
		mid = lo + (hi - lo) / 2;
		if (mid  == x / mid) {
			return mid;
		}
		else if (mid < x / mid) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return lo - 1;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// cout << SQR(5) << endl;
	cout << mySqrt(8) << endl;
}