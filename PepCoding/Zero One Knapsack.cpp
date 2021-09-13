#include <bits/stdc++.h>
using namespace std;

int zeroOneKnapsack(vector<int> &weight, vector<int> &value, int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (weight[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - weight[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][k];
}

int main()
{
    int n;
    cin >> n;
    vector<int> value(n);
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
        cin >> value[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    int k;
    cin >> k;
    cout << zeroOneKnapsack(weight, value, n, k);
}