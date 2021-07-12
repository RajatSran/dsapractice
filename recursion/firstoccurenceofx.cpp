#include<bits/stdc++.h>
using namespace std;

int i = -1;
int firstoccurence(vector<int> arr, int idx, int x) {
    if (idx == arr.size() - 1) {
        return -1;
    }
    if (arr[idx] == x) {
        return idx;
    } else {
        int firstidx = firstoccurence(arr, idx + 1, x);
        return firstidx;
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr = {1, 2, 5, 3, 6, 9, 3};
    cout << firstoccurence(arr, 0, 3);
}