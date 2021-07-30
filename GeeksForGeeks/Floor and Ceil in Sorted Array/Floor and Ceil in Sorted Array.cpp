#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int> v, int n, int x)
{
    int low = 0, high = n - 1;
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] <= x)
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}

int findCeil(vector<int> v, int n, int x)
{
    int low = 0, high = n - 1;
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] >= x)
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}