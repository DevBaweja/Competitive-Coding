#include <bits/stdc++.h>
using namespace std;

int countBinary(int n)
{
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));
    dp[0][1] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = dp[1][i - 1];
        dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
    }
    return dp[0][n] + dp[1][n];
}

int main()
{
    int n;
    cin >> n;
    cout << countBinary(n) << endl;
    return 0;
}