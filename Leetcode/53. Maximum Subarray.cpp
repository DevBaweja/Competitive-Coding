#include <bits/stdc++.h>
using namespace std;

// Kadane Algorithm
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int cur = nums[0], ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        int el = nums[i];
        cur = max(el, cur + el);
        ans = max(ans, cur);
    }
    return ans;
}