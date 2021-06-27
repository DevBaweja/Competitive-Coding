#include <bits/stdc++.h>
using namespace std;

int knapSackUtil(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];
    if (wt[n - 1] > W)
    {
        dp[n][W] = knapSackUtil(W, wt, val, n - 1, dp);
        return dp[n][W];
    }

    dp[n][W] = max(val[n - 1] + knapSackUtil(W - wt[n - 1], wt, val, n - 1, dp),
                   knapSackUtil(W, wt, val, n - 1, dp));
    return dp[n][W];
}
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return knapSackUtil(W, wt, val, n, dp);
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = 3;
    cout << knapSack(W, wt, val, n);
    return 0;
}