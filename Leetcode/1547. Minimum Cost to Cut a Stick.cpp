#include <bits/stdc++.h>
using namespace std;

int minCost(int n, vector<int> &cuts)
{

    unordered_set<int> pre;
    for (int el : cuts)
        pre.insert(el);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int g = 0; g <= n; g++)
    {
        int i, j;
        for (i = 0, j = g; j <= n; i++, j++)
        {
            if (!g)
                dp[i][j] = 0;
            else
            {
                int mini = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    if (pre.find(k) != pre.end())
                    {
                        int cost = j - i;
                        int left = dp[i][k];
                        int right = dp[k][j];
                        mini = min(mini, cost + left + right);
                    }
                }
                if (mini == INT_MAX)
                    mini = 0;
                dp[i][j] = mini;
            }
        }
    }

    return dp[0][n];
}