#include<bits/stdc++.h>
using namespace std;

// important** s-'0' we are doing to make it integer
//573 -> all strings that can be there using this number


vector<string> keypad = {".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> keypadcomb(string str) {
    if (str.size() == 0) {
        vector<string> base;
        base.push_back("");
        return base;
    }
    //faith
    string small = str.substr(1);
    vector<string> vsmall = keypadcomb(small);
    vector<string> res;
    //acting on faith
    char s = str[0];
    string code_s = keypad[s - '0'];
    for (auto a : code_s) {
        for (auto x : vsmall) {
            res.push_back(a + x);
        }
    }
    return res;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str = "678";
    vector<string> result = keypadcomb(str);
    for (auto a : result) {
        cout << a << endl;
    }
}