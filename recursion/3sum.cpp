#include<bits/stdc++.h>
#include<iostream>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {

    sort(nums.begin(), nums.end());

    vector<vector<int>> res;

    for (int i = 0; i < int(nums.size()) - 2; i++)
        //i will run till 3rd last element such that
        // 2nd last and last can form the triblet
    {

        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int low = i + 1; int high = nums.size() - 1; int sum = 0 - nums[i]; //sum=-a
            //keeping low at first and high at end
            while (low < high)
            {
                if (nums[low] + nums[high] == sum) //b+c=a;
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    res.push_back(temp);

                    // to avoid dublicates
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;

                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < sum) low++;
                else high--;

            }
        }

    }
    return res;

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> nums = {1, 2, 3, 4, 5, 3, 2, -2, -1, -5, -7, -8, 4, 6};
    vector<vector<int>> output = threeSum(nums);
    for (auto x : output) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

}

