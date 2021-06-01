/*
you are given an array A, of n elements. you haveto remove exactly n/2 elements
from array A and add it ot another array B(initially empty).
Find the maximum and minimum values of differences between these two arrays.
We define the difference between these two arrays as: abs(A[i]-B[i])
*/

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>

int maxdiff(int n, vi array) {
	int sum = 0;
	for (int i = 0; i < n / 2; ++i)
	{
		sum += abs(a[i] - a[n - i]);
	}
	return sum;
}

int mindiff(int n, vi array) {
	int sum = 0;
	for (int i = 0; i < n; i = i + 2)
	{
		sum += abs(a[i] - a[i + 1]);
	}
	return sum;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vi array;
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
	}
	cout << maxdiff(n, array);
	cout << mindiff(n, array);




}