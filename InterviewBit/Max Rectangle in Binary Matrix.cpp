#include <bits/stdc++.h>
using namespace std;

vector<int> nearestLeftSmallest(vector<int> &A, int n)
{
    vector<int> left(n);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && A[i] <= A[s.top()])
            s.pop();
        left[i] = !s.empty() ? s.top() : -1;
        s.push(i);
    }
    return left;
}

vector<int> nearestRightSmallest(vector<int> &A, int n)
{
    vector<int> right(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && A[i] <= A[s.top()])
            s.pop();
        right[i] = !s.empty() ? s.top() : n;
        s.push(i);
    }
    return right;
}

int mah(vector<int> &A, int n)
{
    vector<int> left = nearestLeftSmallest(A, n);
    vector<int> right = nearestRightSmallest(A, n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int l = left[i];
        l++;
        int r = right[i];
        r--;
        int area = 0;
        if (l == r)
            area = A[i];
        else
            area = A[i] * (r - l + 1);
        res = max(res, area);
    }
    return res;
}

int maximalRectangle(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
        dp[0][j] = A[0][j];
    int res = mah(dp[0], m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j])
                dp[i][j] = 1 + dp[i - 1][j];
        }
        res = max(res, mah(dp[i], m));
    }
    return res;
}
