#include <bits/stdc++.h>
using namespace std;

// Tabular
string printLongestCommonSubstr(vector<vector<int>> &dp, int row, int col, string s)
{
    string lcs = "";
    int i = row, j = col;
    while (dp[i][j] != 0)
    {
        lcs.push_back(s[i - 1]);
        i--;
        j--;
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

string longestCommonSubstr(int n, int m, string s1, string s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int row, col;
    int len = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (len < dp[i][j])
                {
                    len = dp[i][j];
                    row = i;
                    col = j;
                }
            }
            else
                dp[i][j] = 0;
    return printLongestCommonSubstr(dp, row, col, s1);
}

int main()
{
    int x = 6, y = 6;
    string s1 = "ABCDGH", s2 = "ACDGHR";

    cout << longestCommonSubstr(x, y, s1, s2);
    return 0;
}