#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &A)
{
    int n = A.size();
    if (!n)
        return 0;
    int res = 0;
    int buy = 0, sell = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] < A[sell])
        {
            res += A[sell] - A[buy];
            buy = i;
        }
        sell++;
    }
    res += A[sell] - A[buy];
    return res;
}

int maxProfit(const vector<int> &A)
{
    int n = A.size();
    if (!n)
        return 0;
    int res = 0;
    int buy = 0, sell = 1;
    while (sell < n)
    {
        if (A[sell] < A[sell - 1])
        {
            res += A[sell - 1] - A[buy];
            buy = sell;
        }
        sell++;
    }
    res += A[sell - 1] - A[buy];
    return res;
}
