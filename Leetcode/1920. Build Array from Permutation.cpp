#include <bits/stdc++.h>
using namespace std;

// Brute Force
vector<int> buildArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
        res[i] = nums[nums[i]];
    return res;
}

// Space Optimized
// Using mod to store two values in a single space
vector<int> buildArray(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
        nums[i] += (nums[nums[i]] % n) * n;
    for (int i = 0; i < n; i++)
        nums[i] /= n;
    return nums;
}