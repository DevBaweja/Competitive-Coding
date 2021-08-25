#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool isPerfectSquare(int num)
{
    ll low = 0;
    ll high = num;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll sq = mid * mid;
        if (sq == num)
            return true;
        if (sq < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}