#include <bits/stdc++.h>
using namespace std;

int eggDropUtil(int n, int f, vector<vector<int>> dp)
{
    if (f == 0 || f == 1)
        return f;
    if (n == 1)
        return f;

    if (dp[n][f] != -1)
        return dp[n][f];

    int mini = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int l, r;
        if (dp[n - 1][k - 1] != -1)
            l = dp[n - 1][k - 1];
        else
            l = eggDropUtil(n - 1, k - 1, dp);
        if (dp[n][f - k] != -1)
            r = dp[n][f - k];
        else
            r = eggDropUtil(n, f - k, dp);

        int res = 1 + max(l, r);
        mini = min(mini, res);
    }
    return dp[n][f] = mini;
}

int eggDrop(int n, int f)
{
    vector<vector<int>> dp(n + 1, vector<int>(f + 1, -1));
    return eggDropUtil(n, f, dp);
}

int main()
{
    int n = 2, f = 10;
    cout << eggDrop(n, f);
    return 0;
}