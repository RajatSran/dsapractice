#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> keypad =
{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

bool isvalidpath(int i, int j) {
    if (i < 0 || i > 3 || j < 0 || j > 2) {
        return false;
    }
    if (keypad[i][j] == '*' || keypad[i][j] == '#') {
        return false;
    }
    return true;
}

int row[] = {0, 0, -1, 0, 1};
int col[] = {0, 1, 0, -1, 1};
int getcountuntil(int i, int j, int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    int ro = 0, co = 0, totalcount = 0;
    for (int m = 0; m < 5; m++)
    {
        ro = i + row[m];
        co = j + row[m];
        if (isvalidpath(ro, co))
            totalcount += getcountuntil(ro, co, n - 1);
    }
    return totalcount;
}

int getcount(int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 10;
    int i = 0, j = 0, totalcount = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (keypad[i][j] != '*' && keypad[i][j] != '#')
                totalcount += getcountuntil(i, j, n);
        }
    }
    return totalcount;

}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << getcount(1) << endl;
    cout << getcount(2) << endl;
    cout << getcount(3) << endl;
    cout << getcount(4) << endl;
    cout << getcount(5) << endl;
    cout << getcount(6) << endl;
    cout << getcount(7) << endl;
}