#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int res = -1, ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j])
                count++;
        }
        if (count)
        {
            res = max(res, count);
            if (res == count)
                ans = i;
        }
    }
    return res == -1 ? -1 : ans;
}

int binarySearch(vector<int> v, int n)
{
    int low = 0;
    int high = n - 1;
    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid])
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int res = -1, ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int count = 0;
        int first = binarySearch(arr[i], m);
        if (first != -1)
            count = m - first;
        if (count)
        {
            res = max(res, count);
            if (res == count)
                ans = i;
        }
    }
    return res == -1 ? -1 : ans;
}

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int res = -1;
    int r = 0, c = m - 1;
    while (r < n && c >= 0)
    {
        if (arr[r][c])
        {
            res = r;
            c--;
        }
        else
            r++;
    }
    return res;
}