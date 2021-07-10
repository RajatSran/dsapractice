#include<bits/stdc++.h>
using namespace std;

/* binary exponensation
need for this algorithm
1)double stores a big number but not accurately
2)pow(a,b) inbuit function returns double
*/


double mypowrecursive(double x, int n) {
	//divide and conquer
	if (n == 0)
		return 1;
	double temp = mypowrecursive(x, abs(n / 2));
	if (n < 0) {
		//n % 2 == 0
		if (!(n & 1))
			return 1 / (temp * temp);
		else
			return 1 / (temp * temp * x);
	}
	else {
		if (!(n & 1))
			return temp * temp;
		else
			return temp * temp * x;
	}
}

double powiteratively(double x, int n) {
	double ans = 1.0;
	//taking a copy of n
	long long nn = n;
	if (nn < 0) nn = -1 * nn;
	while (nn) {
		if (nn % 2) {
			ans = ans * x;
			nn = nn - 1;
		} else {
			x = x * x;
			nn = nn / 2;

		}
	}
	if (n < 0) ans = (double)(1.0) / double(ans);
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << mypowrecursive(12, 2);
}
