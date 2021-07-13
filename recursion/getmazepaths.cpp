#include<bits/stdc++.h>
using namespace std;

vector<string> getmazepaths(int sr, int sc, int dr, int dc) {
    if (sr == dr && sc == dc) {
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> path1;
    vector<string> path2;
    if (sc < dc) {
        path1 = getmazepaths(sr, sc + 1, dr, dc);
    }
    if (sr < dr) {
        path2 = getmazepaths(sr + 1, sc, dr, dc);
    }

    vector<string> paths;
    for (string v : path1) {
        paths.push_back("v" + v);
    }
    for (string h : path2) {
        paths.push_back("h" + h);
    }
    return paths;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<string> result = getmazepaths(0, 0, 3, 2);
    for (auto a : result) {
        cout << a << endl;
    }
}