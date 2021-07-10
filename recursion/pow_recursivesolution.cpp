#include<bits/stdc++.h>
using namespace std;

//do it in log(n) time
double mypowrecursive(double x, int n) {
	if (n == 0)
		return 1;
	double temp = mypowrecursive(x, abs(n / 2));
	if (n < 0) {
		if (n % 2 == 0)
			return 1 / (temp * temp);
		else
			return 1 / (temp * temp * x);
	}
	else {
		if (n % 2 == 0)
			return temp * temp;
		else
			return temp * temp * x;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << mypowrecursive(12, 2);
}
