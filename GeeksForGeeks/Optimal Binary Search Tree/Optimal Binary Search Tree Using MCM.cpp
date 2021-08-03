#include <bits/stdc++.h>
using namespace std;

// Gap MCM
int optimalSearchTree(int keys[], int freq[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][i] = freq[i];
            }
            else if (g == 1)
            {
                int left = freq[i];
                int right = freq[j];
                dp[i][j] = min(left + 2 * right, right + 2 * left);
            }
            else
            {
                int mini = INT_MAX;
                int tf = 0;
                for (int k = i; k <= j; k++)
                {
                    tf += freq[k];
                    int left = (k != i) ? dp[i][k - 1] : 0;
                    int right = (k != j) ? dp[k + 1][j] : 0;
                    mini = min(mini, left + right);
                }
                dp[i][j] = mini + tf;
            }
        }
    }
    return dp[0][n - 1];
}

// Prefix Sum for Frequency
int optimalSearchTree(int keys[], int freq[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // Prefix Sum for freq
    vector<int> fps(n + 1, 0);
    for (int i = 1; i <= n; i++)
        fps[i] = fps[i - 1] + freq[i - 1];

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][i] = freq[i];
            }
            else if (g == 1)
            {
                int a = freq[i];
                int b = freq[j];
                dp[i][j] = min(a + 2 * b, b + 2 * a);
            }
            else
            {
                int mini = INT_MAX;
                int tf = fps[j + 1] - fps[i];
                for (int k = i; k <= j; k++)
                {
                    // tf += freq[k];
                    int left = (k != i) ? dp[i][k - 1] : 0;
                    int right = (k != j) ? dp[k + 1][j] : 0;
                    mini = min(mini, left + right);
                }
                dp[i][j] = mini + tf;
            }
        }
    }
    return dp[0][n - 1];
}