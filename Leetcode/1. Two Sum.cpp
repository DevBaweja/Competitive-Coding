#include <bits/stdc++.h>
using namespace std;

// Hashing
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(target - nums[i]) != m.end())
            res = {m[target - nums[i]], i};
        m[nums[i]] = i;
    }
    return res;
}