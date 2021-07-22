#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull getNthUglyNo(int n)
{
    vector<ull> dp(n, 0);
    dp[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;
    ull next2 = dp[i2] * 2;
    ull next3 = dp[i3] * 3;
    ull next5 = dp[i5] * 5;
    for (int i = 1; i < n; i++)
    {
        ull next = min({next2, next3, next5});
        dp[i] = next;
        if (next == next2)
        {
            i2++;
            next2 = dp[i2] * 2;
        }
        if (next == next3)
        {
            i3++;
            next3 = dp[i3] * 3;
        }
        if (next == next5)
        {
            i5++;
            next5 = dp[i5] * 5;
        }
    }
    return dp[n - 1];
}