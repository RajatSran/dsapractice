// C++ program to decode number of ways
#include <bits/stdc++.h>
using namespace std;

//top down approach
int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n+1);
    dp[n] = 1;
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='0') dp[i]=0;
        else {
            dp[i] = dp[i+1];
            if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) dp[i]+=dp[i+2];
        }
    }
   return s.empty()? 0 : dp[0];   
}

// Driver code
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string x;
	cin >> x;
	cout << numDecodings(x);
	return 0;
}



