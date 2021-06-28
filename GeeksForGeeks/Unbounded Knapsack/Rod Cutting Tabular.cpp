#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - i] + price[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][n];
}

int main()
{
    int n = 8;
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price, n);
    return 0;
}