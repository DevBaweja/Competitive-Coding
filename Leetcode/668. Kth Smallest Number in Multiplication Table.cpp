#include <bits/stdc++.h>
using namespace std;

int findKthNumber(int n, int m, int k)
{
    int low = 1, high = n * m;
    int res;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int enough = 0;
        for (int i = 1; i <= n; i++)
            enough += min(mid / i, m);
        if (enough >= k)
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}