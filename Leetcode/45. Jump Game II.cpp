#include <bits/stdc++.h>
using namespace std;

// Check if it is possible to reach i using j
int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    if (!nums[0])
        return 0;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
            if (dp[j] != INT_MAX && i <= j + nums[j])
                dp[i] = min(dp[i], dp[j] + 1);
    }
    return dp[n - 1];
}

// Mark all places where i can reach
int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    if (!nums[0])
        return 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] != INT_MAX)
        {
            for (int j = i + 1; j <= min(n - 1, i + nums[i]); j++)
                dp[j] = min(dp[j], dp[i] + 1);
        }
    }
    return dp[n - 1];
}

// Can Reach
// O(n)
int canJump(vector<int> &nums)
{
    int n = nums.size();
    int reach = 0;
    for (int i = 0; i < n; i++)
        if (i <= reach)
            reach = max(reach, i + nums[i]);
    return reach >= n - 1;
}

// Left and Right BFS
// Creating ranges and incrementing jump as BFS levels
int jump(vector<int> &nums)
{
    int n = nums.size();
    int reach = 0, jump = 0;
    int left = 0, right = 0;

    while (!(left <= n - 1 && right >= n - 1))
    {
        int reach = 0;
        for (int k = left; k <= right; k++)
            reach = max(reach, k + nums[k]);
        left = right + 1;
        right = reach;
        jump++;
    }
    return jump;
}

// Max Reach BFS
// Implicit BFS
// i == cur means visited all on the current level
// jumps++ means incrementing the level
// cur == reach means queue size for next level
int jump(vector<int> &nums)
{
    int n = nums.size();
    int reach = 0, cur = 0, jump = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (i <= reach)
            reach = max(reach, i + nums[i]);
        if (i == cur)
        {
            jump++;
            cur = reach;
        }
    }
    return jump;
}