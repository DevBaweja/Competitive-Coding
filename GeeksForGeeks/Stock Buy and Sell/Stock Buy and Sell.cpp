#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> stockBuySell(vector<int> A, int n)
{
    int buy = 0, sell = 0;
    vector<vector<int>> res;
    for (int i = 1; i < n; i++)
    {
        if (A[i] >= A[sell])
            sell++;
        else
        {
            if (buy != sell)
                res.push_back({buy, sell});
            buy = i;
            sell = i;
        }
    }
    if (buy != sell)
        res.push_back({buy, sell});
    return res;
}