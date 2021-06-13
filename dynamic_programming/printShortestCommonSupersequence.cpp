// C++ program to print shortest common supersequence
// C++ program to print longest common subsequence
#include <bits/stdc++.h>
using namespace std;

int t[1002][1002];
string longestcommonsubstring(string x, string y, int m, int n) {
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
    //logic for printing table
    string result = "";
    int i = m;
    int j = n;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[i - 1]) {
            i--;
            j--;
            result.push_back(x[i]);
        } else {
            if (t[i - 1][j] >= t[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }

    }
    //reverse(result.begin(), result.end());
    cout << result << endl;

    //logic for removing lcs from total
    string a = x + y;
    string output = "";
    int p1 = result.size() - 1;
    int p2 = m + n - 1;
    while (p1 > 0) {
        if (a[p2] != result[p1]) {
            output += a[j];
            p2--;
        } else {
            p1--;
            p2--;
        }
    }
    reverse(output.begin(), output.end());
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




