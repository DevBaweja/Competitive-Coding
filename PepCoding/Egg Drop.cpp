#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, f;
    cin >> n >> f;
    vector<vector<int>> dp(n + 1, vector<int>(f + 1, -1));

    int mini = INT_MAX;
    for (int j = 0; j <= f; j++)
    {
        dp[1][j] = j;
    }
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= f; j++)
        {
            int mini = INT_MAX;
            for (int k = 1; k < j; k++)
            {
                int res = 1 + max(dp[i][j - k], dp[i - 1][k - 1]);
                mini = min(mini, res);
            }
            dp[i][j] = mini;
        }
    }
    cout << dp[n][f];
    return 0;
}
