#include <bits/stdc++.h>
using namespace std;

// Sliding Window
int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int res = INT_MAX;
    int sum = 0;
    int low = 0, high = 0;
    while (high < n)
    {
        sum += nums[high++];

        while (sum >= target)
        {
            res = min(res, high - low);
            sum -= nums[low++];
        }
    }
    if (res == INT_MAX)
        return 0;
    return res;
}

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int res = INT_MAX;
    int sum = 0;
    int low = 0;
    for (int high = 0; high < n; high++)
    {
        sum += nums[high];

        while (low <= high && sum >= target)
        {
            res = min(res, high - low + 1);
            sum -= nums[low];
            low++;
        }
    }
    if (res == INT_MAX)
        return 0;
    return res;
}