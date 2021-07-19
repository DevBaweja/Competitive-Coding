#include <bits/stdc++.h>
using namespace std;

// Tabular
int paintHouse()
{
    int n;
    cin >> n;
    vector<vector<int>> m(3, vector<int>(n));
    for (int i = 0; i < n; i++)
        cin >> m[0][i] >> m[1][i] >> m[2][i];

    vector<vector<int>> dp(3, vector<int>(n));

    dp[0][0] = m[0][0];
    dp[1][0] = m[1][0];
    dp[2][0] = m[2][0];

    for (int i = 1; i < n; i++)
    {
        dp[0][i] = m[0][i] + min(dp[1][i - 1], dp[2][i - 1]);
        dp[1][i] = m[1][i] + min(dp[0][i - 1], dp[2][i - 1]);
        dp[2][i] = m[2][i] + min(dp[0][i - 1], dp[1][i - 1]);
    }

    cout << min({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]});
    return 0;
}

// Tabular
int paintHouse()
{
    int n;
    cin >> n;
    vector<vector<int>> m(3, vector<int>(n));
    for (int i = 0; i < n; i++)
        cin >> m[0][i] >> m[1][i] >> m[2][i];

    for (int i = 1; i < n; i++)
    {
        int m0 = m[0][i - 1], m1 = m[1][i - 1], m2 = m[2][i - 1];
        m[0][i] += min(m1, m2);
        m[1][i] += min(m0, m2);
        m[2][i] += min(m0, m1);
    }

    cout << min({m[0][n - 1], m[1][n - 1], m[2][n - 1]});
    return 0;
}
// Tabular Space

int paintHouse()
{
    int n;
    cin >> n;
    vector<vector<int>> m(3, vector<int>(n));
    for (int i = 0; i < n; i++)
        cin >> m[0][i] >> m[1][i] >> m[2][i];

    int m0 = m[0][0], m1 = m[1][0], m2 = m[2][0];
    for (int i = 1; i < n; i++)
    {
        int t0 = m0, t1 = m1, t2 = m2;
        m0 = m[0][i] + min(t1, t2);
        m1 = m[1][i] + min(t0, t2);
        m2 = m[2][i] + min(t0, t1);
    }

    cout << min({m0, m1, m2});
    return 0;
}