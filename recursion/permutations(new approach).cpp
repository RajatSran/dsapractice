#include<bits/stdc++.h>
using namespace std;

/*
swapping with everyting in front
*/
vector<string> result;
void permutations(string str, int ptr) {

    if (ptr == str.size() - 1) {
        result.push_back(str);
    }
    for (int i = ptr; i < str.size(); ++i)
    {
        swap(str[ptr], str[i]);//swap with everything after this
        permutations(str, ptr + 1);//recursion
        swap(str[ptr], str[i]);//backtrack
    }
}



void permutaitons1(string s, string ans) {
    if (s.size() == 0) {
        result.push_back(ans);
    }
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        string rest = left + right;
        permutaitons1(rest, ans + c);
    }
}



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str = "abc";
    permutations(str, 0);
    for (auto a : result) {
        cout << a << endl;
    }
    cout << "---------another upproach--------" << endl;
    result.clear();

    permutaitons1(str, "");
    for (auto a : result) {
        cout << a << endl;
    }
}