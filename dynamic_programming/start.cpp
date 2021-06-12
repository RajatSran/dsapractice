#include <bits/stdc++.h>
#include<iostream>
using namespace std;

const int N = 1e3 + 2, MOD = 1e9 + 7;

int dp[N];

int minsquare(int n) {


	if (n == 1 || n == 2 || n == 3 || n == 0)
		return n;

	if (dp[n] != MOD)
	{
		return dp[n];
	}


	for (int i = 0; i * i <= n; ++i)
	{
		dp[n] = min(dp[n], 1 + minsquare(n - i * i));
	}
	return dp[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i < N; ++i)
	{
		dp[i] = MOD;
	}
	int n;
	cin >> n;
	cout << minsquare(n);

}