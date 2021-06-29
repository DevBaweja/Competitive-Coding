#include <bits/stdc++.h>
using namespace std;

int maximumAmount(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = arr[i];
            }
            else if (g == 1)
            {
                dp[i][j] = max(arr[i], arr[j]);
            }
            else
            {
                int v1 = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int v2 = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(v1, v2);
            }
        }
    }
    return dp[0][n - 1];
}
int main()
{
    int n = 4;
    int arr[] = {5, 3, 7, 10};
    cout << maximumAmount(arr, n);
    return 0;
}