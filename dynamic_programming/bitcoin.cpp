#include <bits/stdc++.h>
#include <math.h>
using namespace std;



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int bitcoins;
	cin >> bitcoins;
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	int b1, b2, b3;
	cin >> b1 >> b2 >> b3;
	int product = (max(b1, max(b2, b3)) * max(a1, max( a2, a3)) ) / (min(b1, min(b2, b3)) * min(a1, min( a2, a3))) * bitcoins;
	cout << product;
	return 0;


}
