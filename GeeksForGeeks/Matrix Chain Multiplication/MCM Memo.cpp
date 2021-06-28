#include <bits/stdc++.h>
using namespace std;

int matrixMultiplicationUtil(int arr[], int left, int right, vector<vector<int>> &dp)
{
    if (left == right)
        return 0;
    if (dp[left][right] != -1)
        return dp[left][right];
    int mini = INT_MAX;
    for (int k = left; k < right; k++)
    {
        int res = matrixMultiplicationUtil(arr, left, k, dp) +
                  matrixMultiplicationUtil(arr, k + 1, right, dp) +
                  arr[left - 1] * arr[k] * arr[right];
        mini = min(mini, res);
    }
    return dp[left][right] = mini;
}
int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return matrixMultiplicationUtil(arr, 1, N - 1, dp);
}

int main()
{
    int N = 5;
    int arr[] = {40, 20, 30, 10, 30};
    cout << matrixMultiplication(N, arr);
    return 0;
}