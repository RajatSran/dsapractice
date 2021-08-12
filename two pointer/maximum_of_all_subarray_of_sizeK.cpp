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

	int k ; cin >> k;
	int sum = 0;
	for (int i = 0; i < k; ++i)
	{
		sum += array[i];

	}
	int maxs = sum;
	int i = 0, j = k;
	while (j < n ) {
		sum -= array[i];
		sum += array[j];
		if (maxs < sum) {
			maxs = sum;
		}
		i++; j++;
	}
	cout << maxs;

}