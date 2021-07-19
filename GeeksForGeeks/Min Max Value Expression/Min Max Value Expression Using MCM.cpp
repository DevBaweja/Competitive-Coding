#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, pair<int, int>(0, 0)));

    for (int g = 0; g < n; g += 2)
    {
        for (int i = 0, j = g; j < n; i += 2, j += 2)
        {
            if (g == 0)
            {
                dp[i][j].first = s[i] - '0';
                dp[i][j].second = s[j] - '0';
            }
            else if (g == 2)
            {
                int op = s[i + 1];
                int v1 = s[i] - '0';
                int v2 = s[j] - '0';
                if (op == '+')
                {
                    dp[i][j].first = v1 + v2;
                    dp[i][j].second = v1 + v2;
                }
                if (op == '*')
                {
                    dp[i][j].first = v1 * v2;
                    dp[i][j].second = v1 * v2;
                }
            }
            else
            {

                int mini = INT_MAX;
                int maxi = INT_MIN;
                for (int k = i + 1; k < j; k += 2)
                {
                    int cmin = 0, cmax = 0;
                    if (s[k] == '+')
                    {
                        cmin = dp[i][k - 1].first + dp[k + 1][j].first;
                        cmax = dp[i][k - 1].second + dp[k + 1][j].second;
                    }

                    if (s[k] == '*')
                    {
                        cmin = dp[i][k - 1].first * dp[k + 1][j].first;
                        cmax = dp[i][k - 1].second * dp[k + 1][j].second;
                    }

                    mini = min(mini, cmin);
                    maxi = max(maxi, cmax);
                }
                if (mini != INT_MAX)
                    dp[i][j].first = mini;
                if (maxi != INT_MIN)
                    dp[i][j].second = maxi;
            }
        }
    }

    cout << "Minimum Value -> " << dp[0][n - 1].first;
    cout << endl;
    cout << "Maximum Value -> " << dp[0][n - 1].second;
}