#include <bits/stdc++.h>
using namespace std;

// Tabular Space
int editDistance(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(2, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            int newi = i % 2;
            int previ = (i - 1) % 2;
            if (!i)
                dp[0][j] = j;
            else if (!j)
                dp[newi][0] = i;
            else if (s[i - 1] == t[j - 1])
                dp[newi][j] = dp[previ][j - 1];
            else
                dp[newi][j] = min({dp[previ][j], dp[newi][j - 1], dp[previ][j - 1]}) + 1;
        }
    return dp[n % 2][m];
}