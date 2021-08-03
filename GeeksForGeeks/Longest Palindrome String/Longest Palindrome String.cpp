#include <bits/stdc++.h>
using namespace std;

string longestPalin(string s)
{
    int n = s.size();
    int st = 0;
    int len = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = true;
            else if (g == 1)
            {
                if (s[i] == s[j])
                    dp[i][j] = true;
            }
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1])
                    dp[i][j] = true;
            }

            if (dp[i][j] && g > len)
            {
                len = g;
                st = i;
            }
        }
    }
    return s.substr(st, len + 1);
}