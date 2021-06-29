#include <bits/stdc++.h>
using namespace std;

// Memo
int editDistanceUtil(string s, string t, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s[n - 1] == t[m - 1])
    {
        if (dp[n - 1][m - 1] == -1)
            dp[n][m] = editDistanceUtil(s, t, n - 1, m - 1, dp);
        else
            dp[n][m] = dp[n - 1][m - 1];
        return dp[n][m];
    }
    else
    {
        int m1, m2, m3;
        if (dp[n - 1][m] == -1)
            m1 = editDistanceUtil(s, t, n - 1, m, dp);
        else
            m1 = dp[n - 1][m];
        if (dp[n][m - 1] == -1)
            m2 = editDistanceUtil(s, t, n, m - 1, dp);
        else
            m2 = dp[n][m - 1];
        if (dp[n - 1][m - 1] == -1)
            m3 = editDistanceUtil(s, t, n - 1, m - 1, dp);
        else
            m3 = dp[n - 1][m - 1];
        dp[n][m] = 1 + min({m1, m2, m3});
        return dp[n][m];
    }
}
int editDistance(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return editDistanceUtil(s, t, n, m, dp);
}
