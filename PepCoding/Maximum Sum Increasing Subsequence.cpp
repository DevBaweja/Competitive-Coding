#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    vector<int> dp(n, 0);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int maxi = 0;
        for (int j = 0; j < i; j++)
        {
            if (A[j] <= A[i])
                maxi = max(maxi, dp[j]);
        }
        dp[i] = maxi + A[i];
        res = max(res, dp[i]);
    }
    cout << res;
}