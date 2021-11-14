#include <bits/stdc++.h>
using namespace std;

int countWays(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int j = 1; j * j <= n; j++)
        for (int i = 1; i <= n; i++)
            if (i >= j * j)
                dp[i] += dp[i - j * j];

    return dp[n];
}