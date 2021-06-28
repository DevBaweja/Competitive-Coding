#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    int s = (target + sum);
    if (s % 2 != 0)
        return 0;
    s /= 2;

    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    dp[0][0] = 1;
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!nums[i - 1])
            count *= 2;
        dp[i][0] = count;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (nums[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=s;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][s];
}

int main()
{
    vector<int> nums{1, 1, 1, 1, 1};
    int target = 3;
    cout << findTargetSumWays(nums, target);
    return 0;
}