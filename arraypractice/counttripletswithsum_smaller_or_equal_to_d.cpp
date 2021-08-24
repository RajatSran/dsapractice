#include <bits/stdc++.h>
using namespace std;

long triplets(long t, vector<int> d) {
	sort(d.begin(), d.end());
	int count = 0;
	for (int i = 0; i < d.size() - 2; ++i)
	{
		int l = i + 1;
		int r = d.size() - 1;
		while (l < r) {
			if (d[i] + d[l] + d[r] <= t)
			{
				count += (r - l);
				l++;
			} else {
				r--;
			}
		}
	}
	return count ;
}

void fun(int *ptr) {
	*ptr = 30;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// static int i = 5;
	// if (--i) {
	// 	main();
	// 	cout << i << " ";
	// }

	int y = 20;
	fun(&y);
	cout << y++ + 10 << endl;
	return 0;
	// int n;
	// cin >> n;
	// vector<int> arr(n);
	// for (int i = 0; i < n; ++i)
	// {
	// 	cin >> arr[i];
	// }

	// long num;
	// cin >> num;

	// cout << triplets(num, arr);

}