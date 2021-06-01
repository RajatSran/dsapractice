
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

bool isperfect(int n) {
	int sum = 1;
	for (int i = 0; i < sqrt(n); ++i) {
		if (n % i == 0) {
			if (i == n / i)
			{
				sum += i;
			} else {
				sum += i + n / i;
			}
		}
	}
	if (sum == n && n != 1)
	{
		return true;
	}
	return false;

}

int maxnumofperfect(vector<int> arr, int k, int n) {
	for (int i = 0; i < n; ++i)
	{
		if (isperfect(arr[i]))
		{
			arr[i] = 1;
		} else {
			arr[i] = 0;
		}
	}

	if (n < k)
	{
		cout << "invalid values" << endl;
		return -1;
	}
	int result = 0;
	for (int i = 0; i < k; ++i)
	{
		result += arr[i];
	}

	int sum = result;
	for (int i = k; i < n; ++i)
	{
		sum += arr[i] - arr[i - k];
		result = max(result, sum);
	}

	return result;

}

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
	cout << maxnumofperfect(arr, k , n);

}