#include <bits/stdc++.h>
using namespace std;

int perfectSum(int arr[], int n, int sum)
{
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int j = 0; j <= sum; j++)
        dp[0][j] = 0;
    dp[0][0] = 1;
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!arr[i - 1])
            count *= 2;
        dp[i][0] = count;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
                dp[i][j] %= mod;
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int n = 6;
    int arr[] = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    cout << perfectSum(arr, n, sum);
    return 0;
}