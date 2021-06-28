#include <bits/stdc++.h>
using namespace std;

int unboundedKnapSack(int n, int w, int val[], int wt[])
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - wt[i - 1]] + val[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}
int main()
{
    int n = 2;
    int w = 3;
    int val[] = {1, 1};
    int wt[] = {2, 1};
    cout << unboundedKnapSack(n, w, val, wt);
    return 0;
}