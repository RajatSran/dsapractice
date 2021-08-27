#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m) {
	sort(a.begin(), a.end());
	int i = 0, j = m - 1;
	long long mindiff = INT_MAX;
	while (j < n) {
		long long diff = a[j] - a[i];
		mindiff = min(diff, mindiff);
		i++; j++;
	}
	return mindiff;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<long long> array(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
	}
	int m;
	cin >> m;
	cout << findMinDiff(array, n, m);
}