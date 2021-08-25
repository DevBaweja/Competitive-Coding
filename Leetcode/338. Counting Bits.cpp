#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
    int c = 0;
    while (n)
    {
        c += n & 1;
        n = n >> 1;
    }
    return c;
}

vector<int> countBits(int n)
{
    vector<int> res(n + 1);
    for (int i = 0; i <= n; i++)
        res[i] = count(i);
    return res;
}

// DP
vector<int> countBits(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = dp[i >> 1];
    }
    return dp;
}