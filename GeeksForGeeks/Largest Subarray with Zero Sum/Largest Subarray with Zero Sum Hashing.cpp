#include <bits/stdc++.h>
using namespace std;

// Time- O(n2)
// Space- O(1)
int maxLen(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = arr[i] ? 1 : -1;
        for (int j = i + 1; j < n; j++)
        {
            sum = arr[j] ? sum + 1 : sum - 1;
            if (!sum)
                res = max(res, j - i + 1);
        }
    }
    return res;
}

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