/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> array(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
	}

	//logic starts here
	int mini = INT_MAX;
	int profit = 0;
	for (int i = 0; i < n; ++i)
	{
		mini = min(mini, array[i]);
		profit = max(profit, array[i] - mini);
	}
	cout << profit;

}