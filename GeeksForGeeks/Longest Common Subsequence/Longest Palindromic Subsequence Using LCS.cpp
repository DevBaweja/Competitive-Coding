#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

int longestPalinSubseq(string a)
{
    string b(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int n = a.size();
    return lcs(a, b, n);
}

int main()
{
    string s = "bbabcbcab";
    cout << longestPalinSubseq(s);
    return 0;
}