#include<bits/stdc++.h>
using namespace std;


int firstoccurence(vector<int> arr, int idx, int x) {

    if (arr[idx] == x) {
        return idx;
    } else {
        int firstidx = firstoccurence(arr, idx + 1, x);
        return firstidx;
    }
}

int lastoccurence(vector<int> arr, int idx, int x) {

    if (idx == arr.size()) {
        return -1;
    }
    //faith
    int lastocc = lastoccurence(arr, idx + 1, x);
    //acting on that faith
    if (lastocc == -1) {
        if (arr[idx] == x) {
            return idx;
        }
        else {
            return -1;
        }
    } else {
        return lastocc;
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr = {1, 2, 3, 6, 9, 3, 3};
    cout << firstoccurence(arr, 0, 3) << endl;
    cout << lastoccurence(arr, 0, 3);
}