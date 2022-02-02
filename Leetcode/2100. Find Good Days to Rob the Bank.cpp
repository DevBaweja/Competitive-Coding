#include <bits/stdc++.h>
using namespace std;

// Prefix Suffix
vector<int> goodDaysToRobBank(vector<int> &security, int time)
{
    int n = security.size();
    vector<int> res;
    if (!time)
    {
        for (int i = 0; i < n; i++)
            res.push_back(i);
        return res;
    }

    vector<int> left(n, 1);
    int lcount = 1;
    for (int i = 1; i < n; i++)
    {
        if (security[i - 1] >= security[i])
        {
            lcount++;
            left[i] = lcount;
        }
        else
            lcount = 1;
    }

    vector<int> right(n, 1);
    int rcount = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (security[i + 1] >= security[i])
        {
            rcount++;
            right[i] = rcount;
        }
        else
            rcount = 1;
    }
    for (int i = time; i <= n - time - 1; i++)
        if (min(left[i], right[i]) > time)
            res.push_back(i);
    return res;
}