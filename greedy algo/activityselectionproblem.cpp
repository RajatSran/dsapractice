//activity selection problem
/*
--approach--
sort on the basis of end time:
as you need a activity which can end early
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>

bool activitycompare(pii a, pii b) {
	return (a.second < b.second);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vii activity;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		activity.push_back({x, y});
	}

	sort(activity.begin(), activity.end(), activitycompare);

	int take = 1;
	int end = activity[0].second;

	for (int i = 1; i < n; ++i)
	{
		if (activity[i].first >= end )
		{
			take++;
			end = activity[i].second;
		}
	}
	cout << take;

}
