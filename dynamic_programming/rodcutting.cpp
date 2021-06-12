
#include <bits/stdc++.h>
#include<iostream>
using namespace std;


int rodcutting(int W, vector<int> val, vector<int> wt, int n) {
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

	vector<int> price;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		price.push_back(a);
	}

	vector<int> length;
	for (int i = 0; i < n; ++i)
	{
		length.push_back(i + 1);
	}

	int W;
	cin >> W;

	cout << rodcutting(W, price , length, n);

}