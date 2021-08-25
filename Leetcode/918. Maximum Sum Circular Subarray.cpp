#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int> &nums)
{
    int n = nums.size();
    int curmax = 0;
    int curmin = 0;
    int resmax = INT_MIN;
    int resmin = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        curmax = max(nums[i], curmax + nums[i]);
        resmax = max(curmax, resmax);
        curmin = min(nums[i], curmin + nums[i]);
        resmin = min(curmin, resmin);
    }

    if (resmin == sum)
        return resmax;
    return max(resmax, sum - resmin);
}