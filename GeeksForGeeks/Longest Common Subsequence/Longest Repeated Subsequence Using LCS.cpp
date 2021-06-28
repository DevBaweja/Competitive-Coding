#include <bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str)
{
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && str[i - 1] == str[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n][n];
}

int main()
{
    string str = "axxxy";
    cout << LongestRepeatingSubsequence(str);
    return 0;
}