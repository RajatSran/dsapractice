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

vector<int> output;
vector<int> alloccurence(vector<int> arr, int idx, int x) {
    if (arr.size() == idx) {
        return output;
    }
    if (arr[idx] == x) {
        output.push_back(idx);
        return alloccurence(arr, idx + 1, x);
    } else {
        return alloccurence(arr, idx + 1, x);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> arr = {1, 2, 3, 6, 9, 3, 3};
    cout << "first occurence :" << firstoccurence(arr, 0, 3) << endl;
    cout << "last occurence :" << lastoccurence(arr, 0, 3) << endl;
    cout << "all occurence :" ;
    alloccurence(arr, 0, 3);
    for (int x : output) {
        cout << x << " ";
    }
}