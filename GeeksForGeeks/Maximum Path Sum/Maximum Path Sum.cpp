#include <bits/stdc++.h>
using namespace std;

/*
    // Tabular
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=n-1; i>=0; i--){
            for(int j=0;j<n;j++){
                if(i==n-1)
                    dp[i][j] = matrix[i][j];
                else if(j==0){
                    dp[i][j] = max(dp[i+1][j], 
                    dp[i+1][j+1]) + 
                    matrix[i][j];
                }
                else if(j==n-1){
                    dp[i][j] = max(dp[i+1][j-1], 
                    dp[i+1][j]) + 
                    matrix[i][j];
                }
                else
                {
                    dp[i][j] = max({dp[i+1][j-1], 
                    dp[i+1][j], 
                    dp[i+1][j+1]}) + 
                    matrix[i][j];
                }
            }
        }
        int res = 0;
        for(int j=0;j<n;j++)
            res = max(res, dp[0][j]);
        return res;
    }
*/

// Space Tabular
int maximumPath(int n, vector<vector<int>> matrix)
{
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                matrix[i][j] += max(matrix[i + 1][j],
                                    matrix[i + 1][j + 1]);
            }
            else if (j == n - 1)
            {
                matrix[i][j] += max(matrix[i + 1][j - 1],
                                    matrix[i + 1][j]);
            }
            else
            {
                matrix[i][j] += max({matrix[i + 1][j - 1],
                                     matrix[i + 1][j],
                                     matrix[i + 1][j + 1]});
            }
        }
    }
    int res = 0;
    for (int j = 0; j < n; j++)
        res = max(res, matrix[0][j]);
    return res;
}