#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int j = n;
	for (int i = 0; i < n ; ++i)
	{
		for (int k = 0; k < j; ++k)
		{
			cout << " * ";
		}
		cout << endl;
		j--;
	}


	j = n ;
	for (int i = 0; i < n ; ++i)
	{
		for (int k = 0; k < j - 1; ++k)
		{
			cout << "   ";
		}
		for (int s = j; s > j - i - 1; --s)
		{
			cout << " * ";
		}
		cout << endl;
		j--;
	}
}