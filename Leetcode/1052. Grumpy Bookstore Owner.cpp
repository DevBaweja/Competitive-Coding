#include <bits/stdc++.h>
using namespace std;

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int n = customers.size();
    int res = 0;
    if (minutes >= n)
    {
        for (int i = 0; i < n; i++)
            res += customers[i];
        return res;
    }

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (!grumpy[i])
            res += customers[i];
        else
            flag = true;
    }
    if (!flag)
        return res;

    int sum = 0;
    int cur = 0;
    for (int i = 0; i < minutes; i++)
    {
        if (grumpy[i])
            cur += customers[i];
    }
    sum = max(sum, cur);

    for (int i = minutes; i < n; i++)
    {
        if (grumpy[i - minutes])
            cur -= customers[i - minutes];
        if (grumpy[i])
            cur += customers[i];
        sum = max(sum, cur);
    }

    return res + sum;
}