//indian coin exchange problem
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
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int x;
	cin >> x;
	sort(a.begin(), a.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += x / a[i];
		x -= x / a[i] * a[i];

	}
	cout << ans;

}
