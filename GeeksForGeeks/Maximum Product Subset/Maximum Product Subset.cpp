#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> a, int n)
{
    int zero = 0, neg = 0;
    int mneg = INT_MIN;
    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        if (!a[i])
        {
            zero++;
        }
        else if (a[i] > 0)
        {
            prod *= a[i];
        }
        else
        {
            neg++;
            prod *= a[i];
            mneg = max(mneg, neg);
        }
    }

    int res = 0;
    if (zero == n)
    {
        res = 0;
    }
    else if (neg == 1 && neg + zero == n)
    {
        res = 0;
    }
    else if (neg & 1)
    {
        prod /= mneg;
        res = prod;
    }
    else
    {
        res = prod;
    }
    cout << res << endl;
}