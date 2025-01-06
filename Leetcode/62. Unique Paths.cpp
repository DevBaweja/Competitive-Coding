#include <bits/stdc++.h>
using namespace std;

// DP
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            if (i == m - 1 && j == n - 1)
                dp[i][j] = 1;
            else if (i == m - 1)
                dp[i][j] = dp[i][j + 1];
            else if (j == n - 1)
                dp[i][j] = dp[i + 1][j];
            else
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    return dp[0][0];
}

// DP
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[m - 1][n - 1];
}

// DP Space
int uniquePaths(int m, int n)
{
    vector<int> cur(n, 1);
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            cur[j] += cur[j - 1];
    return cur[n - 1];
}

// Recursion
int uniquePaths(int n, int m) {
    if(n == 0 && m == 0) return 0;
    if(n == 1 || m == 1) return 1;
    return uniquePaths(n-1, m) + uniquePaths(n, m-1);
}

// Recursion
// Time - O(2^(n*m))
// Space - O(n*m)
int uniquePathsUtil(int i, int j, int n, int m) {
    if(i == n-1 && j == m-1)
        return 1;
    if(i>=n || j>=m)
        return 0;
    return uniquePathsUtil(i+1, j, n, m) + uniquePathsUtil(i, j+1, n, m);
}

int uniquePaths(int n, int m) {
    return uniquePathsUtil(0, 0, n, m);
}

// Recursion with DP
// Time - O(n*m)
// Space - O(n*m)
int uniquePathsUtil(int i, int j, int n, int m, vector<vector<int>>& dp) {
    if(i == n-1 && j == m-1)
        return 1;
    if(i>=n || j>=m)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = uniquePathsUtil(i+1, j, n, m, dp) + 
    uniquePathsUtil(i, j+1, n, m, dp);
    return dp[i][j];
}

int uniquePaths(int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return uniquePathsUtil(0, 0, n, m, dp);
}

// Combination
// Will overflow
int factorial(int val) {
    if(val == 0) return 1;
    return val * factorial(val-1);
}
int uniquePaths(int n, int m) {
    int path = n+m-2;
    return factorial(path) / (factorial(n-1) * factorial(m-1));
}

// Combination
// Avoid overflow
int uniquePaths(int n, int m) {
    int path = n+m-2;
    if(n > m)
        swap(n, m);
    double res = 1;
    for(int i=path, j=1; i>path-n+1; i--, j++) {
        res = (res*i)/j;
    }    
    return (int)res;
}

// TODO
// 2304. Minimum Path Cost in a Grid
// 2087. Minimum Cost Homecoming of a Robot in a Grid
// 2400. Number of Ways to Reach a Position After Exactly k Steps