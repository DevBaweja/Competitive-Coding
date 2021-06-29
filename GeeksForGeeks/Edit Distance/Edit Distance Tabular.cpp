#include <bits/stdc++.h>
using namespace std;

// Tabular
int editDistance(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
    return dp[n][m];
}

// Tabular
int editDistance(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // for(int i=0;i<=n;i++)
    // dp[i][0] = i;
    // for(int j=0;j<=m;j++)
    // dp[0][j] = j;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (!i)
                dp[0][j] = j;
            else if (!j)
                dp[i][0] = i;
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
    return dp[n][m];
}