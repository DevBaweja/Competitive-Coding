#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0;
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if ((g == 0) || (s[i] == s[j] && (g == 1 || dp[i + 1][j - 1])))
            {
                dp[i][j] = true;
                count++;
            }
        }
    }
    return count;
}