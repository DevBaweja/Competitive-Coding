#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int> &nums)
{
    int count = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {

        if (m.find(nums[i]) != m.end())
        {
            count += m[nums[i]];
            m[nums[i]]++;
            continue;
        }
        m.insert({nums[i], 1});
    }
    return count;
}