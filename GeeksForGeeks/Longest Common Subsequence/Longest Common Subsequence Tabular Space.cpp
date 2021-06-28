#include <bits/stdc++.h>
using namespace std;

// Tabular
int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(2, vector<int>(y + 1, 0));
    for (int i = 1; i <= x; i++)
        for (int j = 0; j <= y; j++)
        {
            int newi = i % 2;
            int previ = (i - 1) % 2;
            if (!i)
                dp[0][j] = 0;
            else if (!j)
                dp[newi][0] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[newi][j] = dp[previ][j - 1] + 1;
            else
                dp[newi][j] = max(dp[previ][j], dp[newi][j - 1]);
        }
    return dp[x % 2][y];
}

int main()
{
    int x = 6, y = 6;
    string s1 = "ABCDGH", s2 = "AEDFHR";

    cout << lcs(x, y, s1, s2);
    return 0;
}