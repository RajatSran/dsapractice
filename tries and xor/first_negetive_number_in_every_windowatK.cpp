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
	int k;
	cin >> k;

	int count = 0;
	int x = 0;
	for (int i = 0; i < n; ++i)
	{
		x = 0;
		for (int j = i; j < n; ++j)
		{
			x = x ^ array[j];
			if (x == k) {
				count++;
			}
		}
	}
	cout << count;
}