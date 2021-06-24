#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int l = 0;
    int r = n - 1;
    int leftmax = 0;
    int rightmax = 0;
    int result = 0;
    while (l <= r) {
        if (height[l] <= height[r]) {
            if (leftmax <= height[l]) {
                leftmax = height[l];
            } else {
                result += leftmax - height[l];
            }
            l++;
        } else {
            if (rightmax <= height[r]) {
                rightmax = height[r];

            } else {
                result += rightmax - height[r];
            }
            r--;
        }
    }
    return result;

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << trap(height);
}