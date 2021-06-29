#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string s1, string s2, int n, int m)
{
    int res = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
            else
                dp[i][j] = 0;
    return res;
}

int main()
{
    int n = 6, m = 6;
    string s1 = "ABCDGH", s2 = "ACDGHR";
    cout << longestCommonSubstr(s1, s2, n, m);
    return 0;
}