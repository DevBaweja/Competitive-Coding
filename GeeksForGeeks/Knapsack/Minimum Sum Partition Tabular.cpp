#include <bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));
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

    int el;
    for (el = sum / 2; el >= 0; el--)
        if (dp[n][el])
            break;
    return sum - 2 * el;
}

int main()
{
    int n = 4;
    int arr[] = {1, 6, 11, 5};
    cout << minDifference(arr, n);
    return 0;
}