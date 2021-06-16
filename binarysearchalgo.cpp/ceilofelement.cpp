#include <bits/stdc++.h>
using namespace std;


int floor(vector<int> x, int target) {
    int i = 0;
    int j = x.size();
    int result = -1;
    int mid;
    while (i <= j) {
        mid = (i + j) / 2;
        if (x[mid] == target)
        {
            return x[mid];
        } else if (x[mid] < target) {
            i = mid + 1;
        } else {
            result = x[mid];
            j = mid - 1;
        }
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> x = {  -1, 2, 10, 12 , 38};


    cout << floor(x, 4);
    return 0;
}

