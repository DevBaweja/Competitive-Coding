#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid, int m, int k, vector<int> &v)
{
    int n = v.size();
    int count = 0;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= mid)
            cur++;
        else
            cur = 0;
        if (cur == k)
        {
            count++;
            cur = 0;
        }
        if (count == m)
            return true;
    }
    return false;
}

int minDays(vector<int> &v, int m, int k)
{
    int n = v.size();
    if (n < m * k)
        return -1;

    if (k == 1)
    {
        sort(v.begin(), v.end());
        return v[m - 1];
    }
    int low = 1, high = *max_element(v.begin(), v.end());
    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(mid, m, k, v))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}