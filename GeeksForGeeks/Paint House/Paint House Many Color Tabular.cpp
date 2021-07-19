#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> m(n, vector<int>(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            cin >> m[i][j];

    vector<vector<int>> dp(n, vector<int>(k, 0));

    for (int j = 0; j < k; j++)
        dp[0][j] = m[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int mini = INT_MAX;
            for (int t = 0; t < k; t++)
            {
                if (t != j)
                    mini = min(mini, dp[i - 1][t]);
            }
            dp[i][j] = m[i][j] + mini;
        }
    }

    int res = INT_MAX;
    for (int j = 0; j < k; j++)
        res = min(res, dp[n - 1][j]);

    cout << res;
    return 0;
}