/*

two types :
1. memoization (top down)
2. tabulation (bottom up)

key points:
minimization and maximization problems are generaly soved by
dynamic programming
*/
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>

const int N = 1e3 + 2, MOD = 1e9 + 7;


int minsquare(int n) {

	if (n == 1 || n == 2 || n == 3 || n == 4)
		return n;
	int count = MOD;
	for (int i = 0; i * i <= n; ++i)
	{
		count = min(count, minsquare(n - i * i));
	}
	return count;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	cout << minsquare(n);

}