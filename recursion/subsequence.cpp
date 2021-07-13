#include<bits/stdc++.h>
using namespace std;


vector<string> subsequence(string str) {
    //basecondition
    if (str.size() == 0) {
        vector<string> base;
        base.push_back("");
        return base;
    }
    //faith
    string small = str.substr(1);
    vector<string> vsmall = subsequence(small);
    // acting on faith
    char s = str[0];
    vector<string> output;
    for (auto a : vsmall) {
        output.push_back("" + a);
        output.push_back(s + a);
    }
    return output;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str = "asdgj";
    vector<string> result = subsequence(str);
    for (auto a : result) {
        cout << a << endl;
    }
}