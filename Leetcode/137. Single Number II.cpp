#include <bits/stdc++.h>
using namespace std;

// Time- O(n)
// Space- O(n)
int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> m;
    for (int el : nums)
        m[el]++;
    for (pair<int, int> p : m)
        if (p.second == 1)
            return p.first;
    return -1;
}

// Time- O(nlog(n))
// Space- O(1)
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    sort(nums.begin(), nums.end());
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    for (int i = 1; i < n; i += 3)
    {
        if (nums[i] != nums[i - 1])
            return nums[i - 1];
    }
    return -1;
}