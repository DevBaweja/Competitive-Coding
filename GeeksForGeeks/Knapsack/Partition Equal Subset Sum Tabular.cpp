#include <bits/stdc++.h>
using namespace std;

int equalPartition(int n, int arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return 0;
    sum /= 2;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int j = 0; j <= sum; j++)
        dp[0][j] = false;
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n = 4;
    int arr[] = {1, 5, 11, 5};
    cout << equalPartition(n, arr);
    return 0;
}