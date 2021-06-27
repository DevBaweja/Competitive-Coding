#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int n, int arr[], int sum)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
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
    int n = 6;
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << isSubsetSum(n, arr, sum);
    return 0;
}