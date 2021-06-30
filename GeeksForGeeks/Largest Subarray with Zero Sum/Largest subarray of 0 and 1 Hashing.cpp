#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n)
{
    int res = 0;
    map<int, int> m;
    m[0] = -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = arr[i] ? sum + 1 : sum - 1;
        if (m.find(sum) != m.end())
            res = max(res, i - m[sum]);
        else
            m[sum] = i;
    }
    return res;
}