#include <bits/stdc++.h>
using namespace std;

long long int count(int S[], int m, int n)
{
    // Unbounded Knapsack
    vector<vector<long long int>> dp(m + 1, vector<long long int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (S[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - S[i - 1]];
        }
    }
    return dp[m][n];
}

int main()
{
    int n = 4;
    int m = 3;
    int S[] = {1, 2, 3};
    cout << count(S, m, n);
    return 0;
}