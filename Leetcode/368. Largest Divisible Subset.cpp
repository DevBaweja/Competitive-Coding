#include <bits/stdc++.h>
using namespace std;

// LIS
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> res(n);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && v.size() < res[j].size())
                v = res[j];
        }
        v.push_back(nums[i]);
        res[i] = v;
        if (ans.size() < res[i].size())
            ans = res[i];
    }
    return ans;
}