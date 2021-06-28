#include <bits/stdc++.h>
using namespace std;

// Tabular
int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return dp[x][y];
}

int main()
{
    int x = 6, y = 6;
    string s1 = "ABCDGH", s2 = "AEDFHR";

    cout << lcs(x, y, s1, s2);
    return 0;
}