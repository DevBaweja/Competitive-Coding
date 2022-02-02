#include <bits/stdc++.h>
using namespace std;

// MCM
// Left indicate bursting fron i to k-1
// Right indicate bursting fron k+1 to n
// Burst is last survivor.
// Careful to use i-1, j+1 not k-1, k+1

int maxCoins(vector<int> &A)
{
    int n = A.size();
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

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            int maxi = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int burst = ((i != 0) ? nums[i - 1] : 1) * nums[k] * ((j != n - 1) ? nums[j + 1] : 1);
                int left = (i != k) ? dp[i][k - 1] : 0;
                int right = (j != k) ? dp[k + 1][j] : 0;
                maxi = max(maxi, left + right + burst);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[0][n - 1];
}