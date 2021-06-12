// C++ program to print longest common subsequence
#include <bits/stdc++.h>
using namespace std;

int t[1002][1002];
int LCS(string x, string y, int m, int n) {
    //intialization
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

    //filling table according to lcs
    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = t[i - 1][j - 1] + 1;
            } else {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[m][n];

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
    cout <<  (m + n) - LCS(x, y, m, n);
    /* logic --> worst possible - lcs
    abcdgh
    abadah
    (ab)ca(d)ga(h)
    --> abcadagh = 8
    */
    return 0;
}



