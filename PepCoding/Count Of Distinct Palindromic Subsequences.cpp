#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> prev(n, -1);
    vector<int> next(n, -1);
    unordered_map<int, int> pm, nm;
    for (int i = 0; i < n; i++)
    {
        if (pm.find(s[i]) != nm.end())
            prev[i] = pm[s[i]];
        pm[s[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (nm.find(s[i]) != nm.end())
            next[i] = nm[s[i]];
        nm[s[i]] = i;
    }

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0 || g == 1)
                dp[i][j] = g + 1;
            else
            {
                if (s[i] != s[j])
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                else
                {
                    int l = next[i];
                    int r = prev[j];
                    if (l > r)
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
                    else if (l == r)
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
                    else
                        dp[i][j] = 2 * dp[i + 1][j - 1] - dp[l + 1][r - 1];
                }
            }
        }
    }
    cout << dp[0][n - 1];
}