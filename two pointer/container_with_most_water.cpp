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
	vector<int> height(n);
	for (int i = 0; i < n; ++i)
		cin >> height[i];

	int l = 0;
	int r = height.size() - 1;
	int max_water = min(height[l], height[r]) * (r - l);
	while (l <= r) {
		if (height[l] < height[r]) {
			l++;
		} else {
			r--;
		}
		int current = min(height[l], height[r]) * (r - l);
		if (current > max_water)
		{
			max_water = current;
		}
	}
	cout << max_water;
}