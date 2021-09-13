#include <bits/stdc++.h>
using namespace std;

int cs(int arr[], int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int mini = INT_MAX;
        for (int j = 1; j <= arr[i]; j++)
        {
            if (i + j <= n)
                mini = min(mini, dp[i + j]);
        }

        if (mini != INT_MAX)
            dp[i] = mini + 1;
    }
    if (dp[0] == INT_MAX)
        return -1;
    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = cs(arr, n);
    if (res != -1)
        cout << res << endl;
    else
        cout << "null" << endl;
}