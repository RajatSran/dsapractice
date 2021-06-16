#include <bits/stdc++.h>
using namespace std;


int maxelementinbitonic(vector<int> x) {
    int i = 0;
    int j = x.size();
    int result = -1;
    int mid;

    while (i <= j) {
        mid = (i + j) / 2;
        if (i == j)
        {
            return x[i];
        }
        if ((j == i + 1) && x[i] >= x[j])
            return x[i];

        if ((j == i + 1) && x[i] < x[j])
            return x[j];

        if (x[mid] > x[mid - 1] && x[mid] > x[mid + 1])
        {
            return x[mid];
        } else if (x[mid + 1] >= x[mid]) {
            i = mid + 1;
        } else if (x[mid - 1] >= x[mid]) {
            j = mid - 1;
        }
    }
    return x[mid];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> x = {0, 2, -1};


    cout << maxelementinbitonic(x);
    return 0;
}

