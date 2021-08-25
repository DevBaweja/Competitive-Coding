#include <bits/stdc++.h>
using namespace std;

int burstBalloon(vector<int> A, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            int maxi = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int left = i == k ? 0 : dp[i][k - 1];
                int right = j == k ? 0 : dp[k + 1][j];
                int value = (i == 0 ? 1 : A[i - 1]) *
                            A[k] *
                            (j == n - 1 ? 1 : A[j + 1]);
                maxi = max(maxi, left + value + right);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << burstBalloon(A, n);
}