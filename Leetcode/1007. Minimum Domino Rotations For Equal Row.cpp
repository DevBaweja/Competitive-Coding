#include <bits/stdc++.h>
using namespace std;

int minDominoRotations(vector<int> &top, vector<int> &bottom)
{
    int n = top.size();
    int size = 6;
    int res = INT_MAX;
    for (int i = 1; i <= size; i++)
    {
        int count = 0;
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (top[j] == i)
                continue;
            if (bottom[j] != i)
            {
                flag = false;
                break;
            }
            else
                count++;
        }
        if (flag)
            res = min(res, count);
    }

    for (int i = 1; i <= size; i++)
    {
        int count = 0;
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (bottom[j] == i)
                continue;
            if (top[j] != i)
            {
                flag = false;
                break;
            }
            else
                count++;
        }
        if (flag)
            res = min(res, count);
    }

    return res != INT_MAX ? res : -1;
}