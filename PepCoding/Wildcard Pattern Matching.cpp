#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, pattern;
    cin >> str >> pattern;
    int n = str.size(), m = pattern.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;
    for (int j = 1; j <= m && pattern[j - 1] == '*'; j++)
        dp[0][j] = true;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (pattern[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }

    cout << (dp[n][m] ? "true" : "false");
    return 0;
}