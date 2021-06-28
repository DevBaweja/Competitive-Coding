#include <bits/stdc++.h>
using namespace std;

// Unbounded Knapsack
int minCoins(int coins[], int M, int V)
{
    vector<vector<int>> dp(M + 1, vector<int>(V + 1, INT_MAX - 1));

    for (int i = 0; i <= M; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
        }
    }
    if (dp[M][V] == INT_MAX - 1)
        return -1;
    return dp[M][V];
}

int main()
{
    int V = 30;
    int M = 3;
    int coins[] = {25, 10, 5};
    cout << minCoins(coins, M, V);
    return 0;
}