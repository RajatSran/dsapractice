#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>

bool compareworth(pii a, pii b) {
	double v1 = (double) a.first / a.second;
	double v2 = (double) b.first / b.second;
	return v1 > v2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vii items(n);
	for (int i = 0; i < n; ++i)
	{
		int price;
		int weight;
		cin >> price >> weight;
		items[i].first = price;
		items[i].second = weight;
	}
	sort(items.begin(), items.end(), compareworth);

	int w;
	cin >> w;

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (w >= items[i].second) {
			ans += items[i].first;
			w -= items[i].second;
			continue;
		}
		double leftover = (double) items[i].first / items[i].second;
		ans += leftover * w;
	}

	cout << ans;

}