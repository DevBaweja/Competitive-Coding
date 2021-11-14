#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid, vector<int> &quantities, int n)
{
    int count = 0;
    for (int el : quantities)
    {
        int temp = el;
        while (temp)
        {
            temp -= min(temp, mid);
            count++;
            if (count > n)
                return false;
        }
    }
    return true;
}

int minimizedMaximum(int n, vector<int> &quantities)
{
    int m = quantities.size();
    if (m == 1)
        return quantities[m - 1];
    if (n == m)
        return *max_element(quantities.begin(), quantities.end());

    int low = 0;

    int high = *max_element(quantities.begin(), quantities.end());

    int res;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(mid, quantities, n))
        {
            high = mid - 1;
            res = mid;
        }
        else
            low = mid + 1;
    }
    return res;
}