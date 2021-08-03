#include <bits/stdc++.h>
using namespace std;

int canAssign(vector<int> &weights, int days, int maxi)
{
    int n = weights.size();
    int sum = 0, count = 1;
    for (int i = 0; i < n; i++)
    {
        if (weights[i] > maxi)
            return false;
        sum += weights[i];
        if (sum > maxi)
        {
            sum = weights[i];
            count++;
            if (count > days)
                return false;
        }
    }
    return true;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int low = 0, high = 0;
    for (int i = 0; i < n; i++)
    {
        low = max(low, weights[i]);
        high += weights[i];
    }
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canAssign(weights, days, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}