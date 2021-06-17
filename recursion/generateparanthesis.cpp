#include <bits/stdc++.h>
using namespace std;

vector<string> valid;

void generate(string &s, int open, int close) { // left for open and left for closing
    //base condition
    if (open == 0 && close == 0) {
        cout << s << endl;
        valid.push_back(s);
        return;
    }
    if (open > 0) {
        s.push_back('(');
        generate(s, open - 1, close);
        s.pop_back();//adding pop back as we are passing it by reference
    }
    if (close > 0) {
        if (open < close) {
            s.push_back(')');
            generate(s, open, close - 1);
            s.pop_back();//adding pop back as we are passing it by reference
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    string s;
    generate(s, n, n);
    return 0;
}

