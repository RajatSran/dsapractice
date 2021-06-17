#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];
bool palindrome(string s, int i, int j) {
	while (i <= j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int palindromepartition(string s, int i, int j) {
	//start and end
	if (i >= j) {
		return 0;
	}
	if (palindrome(s, i, j)) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int mini = INT_MAX;
	int temp;

	for (int k = i; k <= j - 1; ++k)
	{
		temp = palindromepartition(s, i, k) + palindromepartition(s, k + 1, j) + 1;
		if (temp < mini)
		{
			mini = temp;
		}
	}
	return dp[i][j] = mini;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s = "nitin";
	memset(dp, -1, sizeof dp);
	cout << palindromepartition(s, 0, s.size() - 1);

}