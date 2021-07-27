#include <bits/stdc++.h>
using namespace std;

// DP
int nthSuperUglyNumber(int n, vector<int> &primes)
{
    vector<int> dp(n, 0);
    dp[0] = 1;
    int k = primes.size();
    vector<int> point(k, 0);
    vector<int> next(primes.begin(), primes.end());

    int i = 1;
    while (i < n)
    {
        int mine = *min_element(next.begin(), next.end());
        if (dp[i - 1] != mine)
            dp[i++] = mine;

        int mini = -1;
        for (int j = 0; j < k; j++)
        {
            if (next[j] == mine)
            {
                mini = j;
                break;
            }
        }
        if (mini != -1)
        {
            point[mini]++;
            next[mini] = dp[point[mini]] * primes[mini];
        }
    }

    return dp[n - 1];
}