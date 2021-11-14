#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> &nums, int k)
{

    int n = nums.size();
    if (n == 1 || k == 1)
        return 0;
    k--;
    sort(nums.begin(), nums.end());
    int res = INT_MAX;
    for (int i = 0; i < n - k; i++)
        res = min(nums[i + k] - nums[i], res);
    return res;
}