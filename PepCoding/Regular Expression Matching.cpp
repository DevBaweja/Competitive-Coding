#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, p;
    cin >> s >> p;
    int n = p.size(), m = s.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        if (p[i - 1] == '*')
            dp[i][0] = dp[i - 2][0];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (p[i - 1] == s[j - 1] || p[i - 1] == '.')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[i - 1] == '*')
            {
                bool res = dp[i - 2][j];
                if (p[i - 2] == '.' || p[i - 2] == s[j - 1])
                    res = res || dp[i][j - 1];
                dp[i][j] = res;
            }
        }
    }

    cout << (dp[n][m] ? "true" : "false");
}