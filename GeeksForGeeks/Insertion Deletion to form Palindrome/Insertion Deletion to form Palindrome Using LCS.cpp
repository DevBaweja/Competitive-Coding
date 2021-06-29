#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n][n];
}
int countMin(string a)
{
    int n = a.size();
    string b(a.begin(), a.end());
    reverse(b.begin(), b.end());
    return n - lcs(a, b, n);
}