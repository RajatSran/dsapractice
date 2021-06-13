// C++ program to Longest common substring
#include <bits/stdc++.h>
using namespace std;

//top down approach
int longestCommonSubstring(string text1, string text2) {
	int n1 = text1.size();
	int n2 = text2.size();
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

	int result = 0;
	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
		{
			if (text1[i - 1] == text2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
				result = max(result, dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	return result;
}

// Driver code
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string x;
	string y;
	cin >> x >> y;
	cout << longestCommonSubstring(x, y);
	return 0;
}



