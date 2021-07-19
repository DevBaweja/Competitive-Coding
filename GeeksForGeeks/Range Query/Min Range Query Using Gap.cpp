#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    vector<int> A{-1, 2, 4, 0};
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = A[i];
            else
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]);
        }
    }

    int ri = 1, rj = 2;
    cout << dp[ri][rj] << endl;
}

// Time- O(n2)
// Space- O(n2)
// Query- O(1)