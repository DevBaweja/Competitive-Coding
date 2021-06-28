#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(int len, int arr[])
{
    int n = len - 1;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (!g)
            {
                dp[i][j] = 0;
            }
            else if (g == 1)
            {
                dp[i][j] = arr[i] * arr[j] * arr[j + 1];
            }
            else
            {
                int res = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int l = dp[i][k];
                    int r = dp[k + 1][j];
                    res = min(res, l + r + arr[i] * arr[k + 1] * arr[j + 1]);
                }
                dp[i][j] = res;
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int N = 5;
    int arr[] = {40, 20, 30, 10, 30};
    cout << matrixMultiplication(N, arr);
    return 0;
}