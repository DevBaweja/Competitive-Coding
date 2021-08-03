#include <bits/stdc++.h>
using namespace std;

vector<int> getSmallestLeft(vector<int> arr, int n)
{
    vector<int> v(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[i] <= arr[s.top()])
            s.pop();
        v[i] = !s.empty() ? s.top() : -1;
        s.push(i);
    }
    return v;
}

vector<int> getSmallestRight(vector<int> arr, int n)
{
    vector<int> v(n, 0);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] <= arr[s.top()])
            s.pop();
        v[i] = !s.empty() ? s.top() : n;
        s.push(i);
    }
    return v;
}

int mah(vector<int> arr, int n)
{
    vector<int> left = getSmallestLeft(arr, n);
    vector<int> right = getSmallestRight(arr, n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int li = left[i];
        li++;
        int ri = right[i];
        ri--;
        int area = 0;
        if (li == ri)
            area = arr[i];
        else
            area = arr[i] * (ri - li + 1);
        res = max(res, area);
    }
    return res;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
        dp[0][j] = matrix[0][j] == '1' ? 1 : 0;

    int res = mah(dp[0], m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
                dp[i][j] = 1 + dp[i - 1][j];
        }
        res = max(res, mah(dp[i], m));
    }
    return res;
}