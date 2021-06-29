#include <bits/stdc++.h>
using namespace std;

int maxDistance(int arr[], int n)
{
    int res = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) != m.end())
            res = max(res, i - m[arr[i]]);
        else
            m[arr[i]] = i;
    }
    return res;
}