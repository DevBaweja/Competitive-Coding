#include <bits/stdc++.h>
using namespace std;

// Hashing
int maxSubArrayLen(vector<int> &nums, int k)
{
    int n = nums.size();
    int sum = 0;
    int res = 0;
    unordered_map<int, int> m;
    m[0] = -1;
    for (int i = 0; i < n; i++)
    {
        int el = nums[i];
        sum += el;
        if (m.find(sum - k) != m.end())
            res = max(res, i - m[sum - k]);
        if (m.find(sum) == m.end())
            m[sum] = i;
    }
    return res;
}