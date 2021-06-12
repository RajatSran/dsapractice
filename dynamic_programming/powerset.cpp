#include <bits/stdc++.h>
#include<iostream>
using namespace std;

const int N = 1e3 + 2, MOD = 1e9 + 7;

void powerset(string str, int n) {
	//total (2^n) - 1 subsets will be there
	for (int j = 0; j < (1 << (n)) - 1; ++j) // 2^n-1 --> (1<<n) -1
	{
		string a = "";
		for (int i = 0; i < n; ++i)
		{
			//checking if ith bit is set or not
			if (j & (1 << i))
			{
				a += str[i];
			}
		}
		cout << a << endl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string a;
	cin >> a;
	int n = a.size();
	powerset(a, n);


}