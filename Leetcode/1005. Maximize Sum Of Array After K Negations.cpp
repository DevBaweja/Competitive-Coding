#include <bits/stdc++.h>
using namespace std;

int largestSumAfterKNegations(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0 && k > 0)
        {
            nums[i] = -nums[i];
            k--;
        }
    }

    int sum = 0, mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        mini = min(mini, nums[i]);
    }

    if (k & 1)
        sum -= 2 * mini;
    return sum;
}
