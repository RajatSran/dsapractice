#include<bits/stdc++.h>
using namespace std;

/*
2^4 = 4C0 + 4C1 + 4C2 + 4C3 + 4C4
use this to
*/

// cb->current box, tb->total boxes, ssf-> selection so far, ts-> total selections, asf->answer so far
void combinations(int cb, int tb, int ssf, int ts, string asf) {
    //base
    if (cb > tb) {
        if (ssf == ts) {
            cout << asf << endl;
        }
        return;
    }

    combinations(cb + 1, tb, ssf, ts, asf + "-");
    combinations(cb + 1, tb, ssf + 1, ts, asf + "i");
}

int c = 0;
void valueofcomb(int cb, int tb, int ssf, int ts) {
    if (cb > tb) {
        if (ssf == ts) {
            c++;
        }
        return;
    }
    valueofcomb(cb + 1, tb, ssf + 1, ts);
    valueofcomb(cb + 1, tb, ssf, ts);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //value of 5C2
    combinations(1, 5, 0, 2, "");
    valueofcomb(1, 5, 0, 2);
    cout << "count->" << c;
}