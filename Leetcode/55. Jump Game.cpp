#include <bits/stdc++.h>
using namespace std;

// DP
// Check if it is possible to reach i using j
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j] && nums[j] >= i - j)
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n - 1];
}

// DP
// Marking all places where i can reach
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        if (dp[i])
        {
            for (int j = i + 1; j <= min(n - 1, i + nums[i]); j++)
                dp[j] = dp[j] || dp[i];
        }
    }
    return dp[n - 1];
}

// BFS
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> vis(n, false);
    vis[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        if (temp == n - 1)
            return true;
        for (int k = temp + 1; k <= min(n - 1, temp + nums[temp]); k++)
            if (!vis[k])
            {
                q.push(k);
                vis[k] = true;
            }
    }
    return false;
}

// Linear Max Reach
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int reach = 0;
    for (int i = 0; i < n; i++)
    {
        if (i <= reach)
            reach = max(reach, i + nums[i]);
    }
    return (reach >= n - 1);
}