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

	int p1 = 0, p2 = array.size() - 1;
	while (p1 + 1 <= p2 ) {
		if (array[p1] < 0) {
			p1++;
		}
		if (array[p2] > 0) {
			p2--;
		}
		if (array[p1] > 0 && array[p2] < 0) {
			int temp = array[p1];
			array[p1] = array[p2];
			array[p2] = temp;
			p1++;
			p2--;
		}
	}

	for (int i = 0; i < array.size(); ++i)
	{
		cout << array[i] << " ";
	}
}