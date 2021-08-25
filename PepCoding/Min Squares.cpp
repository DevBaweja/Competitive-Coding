#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int mini = i;
        for (int j = 1; j * j <= i; j++)
        {
            int val = i - j * j;
            mini = min(mini, dp[val]);
        }
        dp[i] = mini + 1;
    }
    cout << dp[n];
}