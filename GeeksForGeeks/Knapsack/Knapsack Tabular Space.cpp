#include <bits/stdc++.h>
using namespace std;

// Space Optimized Tabular
int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> dp(W + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = W; j >= wt[i]; j--)
        {
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }
    return dp[W];
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