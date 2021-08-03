#include <bits/stdc++.h>
using namespace std;

bool canSplit(vector<int> &nums, int m, int maxi)
{
    int n = nums.size();
    int sum = 0, count = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > maxi)
            return false;
        sum += nums[i];
        if (sum > maxi)
        {
            sum = nums[i];
            count++;
            if (count > m)
                return false;
        }
    }
    return true;
}

int splitArray(vector<int> &nums, int m)
{
    int n = nums.size();
    int low = 0, high = 0;
    for (int i = 0; i < n; i++)
    {
        low = max(low, nums[i]);
        high += nums[i];
    }
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canSplit(nums, m, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}