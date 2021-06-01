
#include <bits/stdc++.h>
#include<iostream>
using namespace std;


bool isPalindrome(int a) {
	int temp = a, number = 0;
	while (temp > 0) {
		number = number * 10 + temp % 10;
		temp = temp / 10;
	}
	if (number == a)
	{
		return true;
	}
	return false;
}

int palindromeconc(vector<int> arr, int k , int n) {
	int num = 0;
	for (int i = 0; i < k; ++i)
	{
		num = num * 10 + arr[i];
	}

	if (isPalindrome(num))
	{
		return 0;
	}

	for (int j = k; j < n; ++j)
	{
		num = (num % (int)pow(10, k - 1)) * 10 + arr[j];
		if (isPalindrome(num))
		{
			return (j - k + 1);
		}
	}
	return -1;
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
	cout << palindromeconc(arr, k , n);



}