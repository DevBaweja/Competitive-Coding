#include <bits/stdc++.h>
using namespace std;

long long trian(int n)
{
    if (n <= 1)
        return 0;
    vector<long long> dp(n - 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int k = 2; k <= n - 2; k++)
        for (int i = 0, j = k - 1; i < k && j >= 0; i++, j--)
            dp[k] += dp[i] * dp[j];
    return dp[n - 2];
}

int main()
{
    int n;
    cin >> n;
    cout << trian(n);
    return 0;
}