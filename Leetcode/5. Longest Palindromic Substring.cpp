#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    pair<int, int> p;
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if ((g == 0) || (s[i] == s[j] && (g == 1 || dp[i + 1][j - 1])))
            {
                dp[i][j] = true;
                p = {i, j - i + 1};
            }
        }
    }
    return s.substr(p.first, p.second);
}