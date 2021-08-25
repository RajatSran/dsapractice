#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool subArrayExists(vector<int> arr, int n)
{
    unordered_set<int> s;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0 || s.find(sum) != s.end()) {
            return true;
        }
        s.insert(sum);
    }
    return false;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }
    cout << subArrayExists(array, n);
}
