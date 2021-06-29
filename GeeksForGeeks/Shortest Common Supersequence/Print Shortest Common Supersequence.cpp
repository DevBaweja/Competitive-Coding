#include <bits/stdc++.h>
using namespace std;

string printShortestCommonSupersequence(string X, string Y, int m, int n, vector<vector<int>> &dp)
{
    string str = "";

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            str.push_back(X[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            str.push_back(Y[j - 1]);
            j--;
        }
        else
        {
            str.push_back(X[i - 1]);
            i--;
        }
    }

    while (i > 0)
    {
        str.push_back(X[i - 1]);
        i--;
    }

    while (j > 0)
    {
        str.push_back(Y[j - 1]);
        j--;
    }

    reverse(str.begin(), str.end());
    return str;
}

string shortestCommonSupersequence(string X, string Y, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return printShortestCommonSupersequence(X, Y, m, n, dp);
}

int main()
{
    string X = "abcd", Y = "xycd";
    int m = X.size(), n = Y.size();
    cout << shortestCommonSupersequence(X, Y, m, n);
    return 0;
}