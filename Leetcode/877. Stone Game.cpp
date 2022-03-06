#include <bits/stdc++.h>
using namespace std;

// Getting sum of even and odd elements,
// Player one can force other player to select only one type of element
bool stoneGame(vector<int> &piles)
{
    return true;
}

// DP optimal game
bool stoneGame(vector<int> &piles)
{
    int n = piles.size();
    int sum = 0;
    for (int el : piles)
        sum += el;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (!g)
                dp[i][j] = piles[i];
            else if (g == 1)
                dp[i][j] = max(piles[i], piles[j]);
            else
            {
                int v1 = piles[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int v2 = piles[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(v1, v2);
            }
        }
    }
    return dp[0][n - 1] > sum / 2;
}