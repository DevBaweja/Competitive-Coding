#include <bits/stdc++.h>
using namespace std;

// Subsets
void subsets(vector<int> &nums, int index, vector<int> &res, int &count, int maxi)
{
    int n = nums.size();
    if (index == n)
    {
        int cur = 0;
        for (int el : res)
            cur |= el;
        count += cur == maxi;
        return;
    }
    res.push_back(nums[index]);
    subsets(nums, index + 1, res, count, maxi);
    res.erase(res.end() - 1);
    subsets(nums, index + 1, res, count, maxi);
}

int countMaxOrSubsets(vector<int> &nums)
{
    int maxi = 0;
    for (int el : nums)
        maxi |= el;

    vector<vector<int>> ans;
    int index = 0;
    vector<int> res;
    int count = 0;
    subsets(nums, index, res, count, maxi);
    return count;
}

// Bit Masking
int countMaxOrSubsets(vector<int> &nums)
{
    int n = nums.size();

    int maxi = 0;
    for (int el : nums)
        maxi |= el;
    int count = 0;

    for (int mask = 1; mask < (1 << n); mask++)
    {
        int res = 0;
        for (int index = 0; index < n; index++)
        {
            if (mask & 1 << index)
                res |= nums[index];
        }
        count += res == maxi;
    }
    return count;
}