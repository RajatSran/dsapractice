#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int r;
	cin >> r;
	int c;
	cin >> c;
	for (int i = 0; i < r ; ++i)
	{
		for (int j = 0; j < c ; ++j)
		{
			if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
			{
				cout << " * ";
			} else {
				cout << "   ";
			}

		}
		cout << endl;
	}


}