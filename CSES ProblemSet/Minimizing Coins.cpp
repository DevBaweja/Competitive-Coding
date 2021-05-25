#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    vector<int> dp(x + 1);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        dp[i] = 1e9;
        for (int j = 0; j < n; j++)
            if (i >= coins[j])
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    }
    cout << dp[x];
    return 0;
}