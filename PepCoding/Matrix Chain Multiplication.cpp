#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    n--;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int g = 1; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 1)
                dp[i][j] = A[i] * A[j] * A[j + 1];
            else
            {
                int mini = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int l = dp[i][k];
                    int r = dp[k + 1][j];
                    int m = A[i] * A[k + 1] * A[j + 1];
                    mini = min(mini, l + r + m);
                }
                dp[i][j] = mini;
            }
        }
    }
    cout << dp[0][n - 1];
}