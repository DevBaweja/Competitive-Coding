#include <bits/stdc++.h>
using namespace std;

int lcs(string str1, string str2, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int minOperations(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    return m + n - 2 * lcs(str1, str2, m, n);
}

int main()
{
    string str1 = "heap", str2 = "pea";
    cout << minOperations(str1, str2);
    return 0;
}