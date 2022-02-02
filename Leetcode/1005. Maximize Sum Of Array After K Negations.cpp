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

// Brute Force
int largestSumAfterKNegations(vector<int> &nums, int k)
{
    int n = nums.size();
    int zero = 0, negative = 0;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int el = nums[i];
        zero += (!el);
        if (!el)
            zero++;
        else if (el < 0)
        {
            negative++;
            maxi = max(maxi, el);
            sum -= el;
        }
        else
        {
            mini = min(mini, el);
            sum += el;
        }
    }

    if (negative && negative <= k)
    {
        k -= negative;
        if (zero)
            return sum;
        cout << k << "  ";
        if (k & 1)
        {
            int temp = min(-maxi, mini);
            return sum - 2 * temp;
        }
        return sum;
    }

    if (negative)
    {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < k; i++)
            res -= nums[i];
        for (int i = k; i < n; i++)
            res += nums[i];
        return res;
    }

    return sum - 2 * mini;
}