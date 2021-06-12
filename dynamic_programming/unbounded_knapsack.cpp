/*
input=
4
10
40
50
70
1
3
4
5
8

output=110;
*/
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int unboundedknapsack(int W, vector<int> val, vector<int> wt, int n) {
	int size, weight;
	int dp[n + 1][W + 1];

	for (int size = 0; size < n + 1; ++size)
	{
		for (int weight = 0; weight < W + 1; ++weight)
		{
			if (size == 0 || weight == 0) {
				dp[size][weight] = 0;
			} else if (wt[size - 1] <= weight) {
				dp[size][weight] =
				    max(val[size - 1] + dp[size - 1][weight - wt[size - 1]]
				        , dp[size - 1][weight]);
			} else {
				dp[size][weight] = dp[size - 1][weight];
			}
		}
	}
	return dp[n][W];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	vector<int> val;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		val.push_back(a);
	}

	vector<int> wt;
	for (int i = 0; i < n; ++i)
	{
		int b;
		cin >> b;
		wt.push_back(b);
	}

	int W;
	cin >> W;

	cout << unboundedknapsack(W, val , wt, n);

}