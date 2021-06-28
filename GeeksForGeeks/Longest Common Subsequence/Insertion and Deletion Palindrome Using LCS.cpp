#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string k, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == k[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}
int minimumNumberOfInsertionOrDeletions(string s)
{
    int n = s.size();
    string k(s.begin(), s.end());
    reverse(k.begin(), k.end());
    return n - lcs(s, k, n);
}
int main()
{
    string s = "aebcbda";
    cout << minimumNumberOfInsertionOrDeletions(s);
    return 0;
}