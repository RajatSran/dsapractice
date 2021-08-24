#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>>ans;
	if (intervals.size() == 0)
		return ans;
	sort(intervals.begin(), intervals.end());
	int f = intervals[0][0];
	int e = intervals[0][1];
	for (int i = 0; i < intervals.size(); i++) {
		int f1 = intervals[i][0];
		int e1 = intervals[i][1];
		if (max(f, f1) <= min(e, e1)) {
			f = min(f, f1);
			e = max(e, e1);
		} else {
			ans.push_back({f, e});
			f = f1;
			e = e1;
		}
	}
	ans.push_back({f, e});
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>> intervals ;
	intervals.push_back({1, 3});
	intervals.push_back({2, 6});
	intervals.push_back({8, 10});
	intervals.push_back({15, 18});
	merge(intervals);


}