#include <bits/stdc++.h>
using namespace std;

int arithmeticSlice(vector<int> A, int n)
{
    vector<int> dp(n, 0);
    int res = 0;
    for (int i = 2; i < n; i++)
    {
        if (A[i - 1] - A[i - 1] == A[i - 1] - A[i])
        {
            dp[i] = 1 + dp[i - 1];
            res += dp[i];
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int res = arithmeticSlice(A, n);
    cout << res << endl;
}