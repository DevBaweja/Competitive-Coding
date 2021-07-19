#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int n, int a[])
{
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        int maxi = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                maxi = max(maxi, dp[j]);
        }
        dp[i] = maxi + 1;
    }
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
        res = max(res, dp[i]);
    return res;
}