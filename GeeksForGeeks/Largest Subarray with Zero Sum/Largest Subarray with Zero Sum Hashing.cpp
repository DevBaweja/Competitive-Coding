#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n)
{
    int res = 0;
    int sum = 0;
    map<int, int> m;
    m[0] = -1;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (m.find(sum) != m.end())
            res = max(res, i - m[sum]);
        else
            m[sum] = i;
    }
    return res;
}