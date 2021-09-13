#include <bits/stdc++.h>
using namespace std;

int cs(int arr[], int n)
{
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int sum = 0;
        for (int j = 1; j <= arr[i]; j++)
        {
            if (i + j <= n)
                sum += dp[i + j];
        }
        dp[i] = sum;
    }

    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << cs(arr, n) << endl;
}