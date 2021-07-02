#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    vector<int> dp(n, -1);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] != 0)
        {
            int mini = INT_MAX;
            for (int j = 1; j <= arr[i] && i + j < n; j++)
            {
                if (dp[i + j] != -1)
                    mini = min(mini, dp[i + j]);
            }
            if (mini != INT_MAX)
                dp[i] = 1 + mini;
        }
    }
    return dp[0];
}