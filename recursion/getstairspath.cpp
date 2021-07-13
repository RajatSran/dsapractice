#include<bits/stdc++.h>
using namespace std;

//testcase
// 3-> 111, 12, 21, 3

vector<string> stairspath(int n) {
    if (n == 0) {
        vector<string> base;
        base.push_back("");
        return base;
    } else if ( n < 0) {
        vector<string> base;
        return base;
    }
    //faith
    vector<string> path1 = stairspath(n - 1);
    vector<string> path2 = stairspath(n - 2);
    vector<string> path3 = stairspath(n - 3);
    //acting on it
    vector<string> paths;

    for (string path : path1) {
        paths.push_back("1" + path);
    }

    for (string path : path2) {
        paths.push_back("2" + path);
    }

    for (string path : path3) {
        paths.push_back("3" + path);
    }
    return paths;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int count_of_stairs = 5;
    vector<string> result = stairspath(count_of_stairs);
    for (auto a : result) {
        cout << a << endl;
    }
}