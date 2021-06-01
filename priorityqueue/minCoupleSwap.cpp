#include <iostream>
using namespace std;

int minSwapsCouples(vector<int> row) { // each couch has two seats for a couple to sit. Initially for row[0] and row[1], the couch id is 0, and so on.
    int N = row.size();
    int ans = 0;
    unordered_map<int, int> couchNum;   // storing which number belongs to which couch
    for (int i = 0; i < N; i++) couchNum[row[i]] = i / 2;

    vector<bool> visited (N / 2, false);
    for (int couch = 0; couch < N / 2; couch++) {
        if (!visited[couch]) {
            int tempCouch = couch;
            do {
                // figure out how many couches belong to the connected component. All connected component are similar to polygons, except duplet and singlet couches.
                ans++;
                visited[tempCouch] = true;
                int firstPerson = row[2 * tempCouch];
                int secondPerson = row[2 * tempCouch + 1];

                int couchOfFirstPersonPartner, couchOfSecondPersonPartner;

                if (firstPerson % 2 == 0) couchOfFirstPersonPartner = couchNum[firstPerson + 1];
                else couchOfFirstPersonPartner = couchNum[firstPerson - 1];

                if (secondPerson % 2 == 0) couchOfSecondPersonPartner = couchNum[secondPerson + 1];
                else couchOfSecondPersonPartner = couchNum[secondPerson - 1];

                if (!visited[couchOfFirstPersonPartner]) tempCouch = couchOfFirstPersonPartner;
                else if (!visited[couchOfSecondPersonPartner]) tempCouch = couchOfSecondPersonPartner;
                else break;
            }
            while (tempCouch != couch);
            ans--;     // If a connected component has n couches, we need to add n-1 to our ans.
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    vector<int> result = topKFrequent(nums, k);

}
