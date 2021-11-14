#include <bits/stdc++.h>
using namespace std;

// DP
int numSquares(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    return dp[n];
}

// BFS
int numSquares(int n)
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    vector<int> vis(n + 1, 0);
    vis[n] = 1;
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int value = p.first;
            int step = p.second;
            if (!value)
                return step;
            int sq = 1;
            while (sq * sq <= value)
            {
                if (!vis[value - sq * sq])
                {
                    vis[value - sq * sq] = 1;
                    q.push({value - sq * sq, step + 1});
                }
                sq++;
            }
        }
    }
    return -1;
}