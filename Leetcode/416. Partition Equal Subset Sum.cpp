#include <bits/stdc++.h>
using namespace std;

// DP
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int el : nums)
        sum += el;
    if (sum & 1)
        return false;

    sum = sum >> 1;

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (nums[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        }
    }

    return dp[n][sum];
}