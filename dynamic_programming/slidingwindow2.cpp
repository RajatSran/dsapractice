
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
	cin >> k;

	int i = 0;
	pair<int, int> ans;
	int sum = 0;
	for (int i = 0; i < k; ++i)
	{
		sum += arr[i];
	}

	bool found = false;
	if (sum % 3 == 0)
	{
		found = true;
		ans = make_pair(0, k - 1);
	}

	for (int i = k; i < n; ++i)
	{
		if (found)
		{
			break;
		}

		sum += arr[i] - arr[i - k];

		if (sum % 3 == 0)
		{
			found = true;
			ans = make_pair(i - k + 1, i );
		}
	}

	if (!found)
	{
		ans = make_pair(-1, 0);
	}
	if (ans.first == -1 )
	{
		cout << "no such subarray exists";
	}
	else {
		for (int i = ans.first; i < ans.second + 1; ++i)
		{
			cout << arr[i] << " ";
		}
	}







}