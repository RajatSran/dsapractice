
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long
#define pb push_back


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int n;
        cin >> n;

        vector<vector<int>>arr(n);

        priority_queue<int, vector<int>, greater<int>>pq;

        ll ans = 0;

        for (int i = 0; i < n; ++i)
        {
            int k; cin >> k;

            arr[i] = vector<int>(k);

            for (int j = 0; j < k; j++)
            {
                int x; cin >> x;
                arr[i][j] = x;
            }

            int j = 0, pre = -1, id = 0;
            vector<int>v;

            while (j < k)
            {
                if (arr[i][j] > pre) {
                    pre = arr[i][j];
                    j++;
                }
                else
                {
                    pre = -1;
                    v.pb(j - id);
                    id = j;
                }
            }

            v.pb(j - id);

            sort(v.begin(), v.end());

            for (int j = 0; j < (int)v.size() - 1; j++)ans += v[i];
            for (int j = 0; j < v.size(); j++)pq.push(v[j]);
        }

        while (pq.size() > 1)
        {
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            ans += (x + y);
            pq.push(x + y);
        }

        cout << ans << endl;
    }

}