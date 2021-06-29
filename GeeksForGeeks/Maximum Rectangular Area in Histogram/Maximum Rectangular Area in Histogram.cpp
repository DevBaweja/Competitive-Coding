#include <bits/stdc++.h>
using namespace std;

vector<int> getSmallestLeft(long long arr[], int n)
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

vector<int> getSmallestRight(long long arr[], int n)
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

long long getMaxArea(long long arr[], int n)
{
    vector<int> left = getSmallestLeft(arr, n);
    vector<int> right = getSmallestRight(arr, n);

    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        int li = left[i];
        li++;
        int ri = right[i];
        ri--;

        long long area = 0;
        if (li == ri)
            area = arr[i];
        else
            area = arr[i] * (ri - li + 1);
        res = max(res, area);
    }
    return res;
}