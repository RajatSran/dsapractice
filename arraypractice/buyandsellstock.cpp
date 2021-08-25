#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>

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