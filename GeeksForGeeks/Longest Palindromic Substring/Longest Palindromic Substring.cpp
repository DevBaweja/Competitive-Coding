#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    string res = "";
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (!g)
                dp[i][j] = true;
            else if (g == 1)
                dp[i][j] = s[i] == s[j];
            else
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];

            if (dp[i][j] && g + 1 > res.size())
                res = s.substr(i, g + 1);
        }
    }
    return res;
}