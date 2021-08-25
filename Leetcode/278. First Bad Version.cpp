#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isBadVersion(int mid)
{
}

int firstBadVersion(int n)
{
    ll low = 1;
    ll high = n;
    ll res = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (isBadVersion(mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return (int)res;
}