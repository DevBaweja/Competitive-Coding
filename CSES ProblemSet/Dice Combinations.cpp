#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    int m = 1e9 + 7;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= min(i, 6); j++)
            dp[i] = (dp[i] + dp[i - j]) % m;
    cout << dp[n];
    return 0;
}
