// C++ program to decode number of ways
#include <bits/stdc++.h>
using namespace std;

int t[1002][1002];
int longestcommonsubstring(string x, string y, int m, int n) {
    //intialization
    int result = 0;
    for (int i = 0; i < m + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = t[i - 1][j - 1] + 1;
                result = max(result, t[i][j]);
            } else {
                t[i][j] = 0;
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
    int m = x.size(), n = y.size();
    cout << longestcommonsubstring(x, y, m, n);
    return 0;
}



