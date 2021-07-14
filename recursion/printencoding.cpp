#include<bits/stdc++.h>
using namespace std;

void encoding(string str, string asf) {
    //base case
    if (str.size() == 0) {
        cout << asf << endl;
    } else if (str.size() == 1) {
        char ch = str[0];
        if (ch == '0') {
            return;
        }
        else {
            int chv = ch - '0';// for converting char to int
            char code = 'a' + chv - 1; //as 0->"a"
            cout << asf + code << endl;
        }
    } else {
        //taking one character at a time
        char ch = str[0];
        string roq = str.substr(1);
        if (ch == '0') {
            return;
        }
        else {
            int chv = ch - '0';// for converting char to int
            char code = 'a' + chv - 1; //as 0->"a"

            encoding(roq, asf + code);
        }

        //taking two character at a time
        string ch12 = str.substr(0, 2);
        roq = str.substr(2);
        // inbuilt function in c++ to convert string to integer
        int ch12v = stoi(ch12);
        if (ch12v <= 26) {
            char code = 'a' + ch12v - 1;

            encoding(roq, asf + code);
        }

    }


}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    encoding("123", "");
}