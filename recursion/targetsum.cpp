#include<bits/stdc++.h>
using namespace std;

void targetsum1(vector<int> array, int ptr, vector<int> output, int sos, int k) {
    if (ptr == array.size()) {
        if (sos == k)
        {
            for (int x : output)
                cout << x << ", ";
            cout << endl;
        }
        return;
    }

    targetsum1(array, ptr + 1, output, sos , k);
    output.push_back(array[ptr]);
    targetsum1(array, ptr + 1, output, sos + array[ptr], k);

}

void targetsum(vector<int> array, int ptr, string set, int sos, int k) {
    if (ptr == array.size()) {
        if (sos == k)
        {
            cout << set << endl;
        }
        return;
    }

    targetsum(array, ptr + 1, set + to_string(array[ptr]) + ", ", sos + array[ptr], k);
    targetsum(array, ptr + 1, set, sos , k);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> output;
    string set = "";
    int k = 70 ;
    int sos = 0;
    int ptr = 0;
    vector<int> array = {10, 20, 30, 40, 50};
    targetsum(array, ptr, set, sos, k);
    cout << endl;
    targetsum1(array, ptr, output, sos, k);
}