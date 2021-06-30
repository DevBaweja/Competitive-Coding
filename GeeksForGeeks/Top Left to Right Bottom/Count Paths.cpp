#include <bits/stdc++.h>
using namespace std;

// Tabular
/*
    long long int numberOfPaths(int m, int n){
        vector<vector<long long int>> dp(m, vector<long long int>(n,1));
        int mod = 1e9+7;
        for(int i=1;i<m; i++)
            for(int j=1;j<n;j++)
            {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
                dp[i][j] = dp[i][j] % mod;
            }
        return dp[m-1][n-1];
    }
*/

// Inverse Tabular
/*
    long long int numberOfPaths(int m, int n){
        vector<long long int> dp(n,1);
        int mod = 1e9+7;
        for(int i=1;i<m; i++)
            for(int j=1;j<n;j++)
            {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
                dp[i][j] = dp[i][j] % mod;
            }
        return dp[m-1][n-1];
    }
*/

// Maximum Space Tabular
long long int numberOfPaths(int m, int n)
{
    vector<long long int> dp(n, 1ll);
    int mod = 1e9 + 7;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
        {
            dp[j] += dp[j - 1];
            dp[j] = dp[j] % mod;
        }
    return dp[n - 1];
}