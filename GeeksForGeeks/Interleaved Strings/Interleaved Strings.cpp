#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C)
{
    int n = A.size();
    int m = B.size();
    int nm = C.size();
    if (nm != n + m)
        return false;
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
        if (A[i - 1] == C[i - 1])
            dp[i][0] = true;
        else
            break;
    for (int j = 1; j <= m; j++)
        if (B[j - 1] == C[j - 1])
            dp[0][j] = true;
        else
            break;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int res = false;
            if (A[i - 1] == C[i + j - 1])
                res |= dp[i - 1][j];
            if (B[j - 1] == C[i + j - 1])
                res |= dp[i][j - 1];
            dp[i][j] = res;
        }
    }
    return dp[n][m];
}
