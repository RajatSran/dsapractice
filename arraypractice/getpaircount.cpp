
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getPairsCount(vector<int> arr, int n, int k) {
	unordered_map<int, int> m;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (m.find(k - arr[i]) != m.end()) {
			count += m[k - arr[i]];
		}
		m[arr[i]]++;
	}
	return count;
}

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
	cout << getPairsCount(array, n, k);

}