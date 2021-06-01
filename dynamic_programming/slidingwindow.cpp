
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int k;
	int x;
	cin >> k >> x;
	cout << k << " " << x << endl;

	int ans = 0;
	int sum = 0;
	for (int i = 0; i < k; ++i)
	{
		sum += arr[i];
	}

	if (sum < x)
	{
		ans = sum;
	}

	cout << sum << endl;
	for (int i = k; i < n; ++i)
	{
		sum = sum - arr[i - k];
		sum = sum + arr[i];
		cout << i - k << " : " << sum << endl;
		if (sum < x && sum > ans)
		{
			ans = sum;
		} else {
			continue;
		}
	}
	cout << ans << " is the maximum sum less than x of subarray k";

}