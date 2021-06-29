#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]] = 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (!m[arr[i] - 1])
        {
            int count = 1;
            while (m[arr[i] + count])
                count++;
            res = max(res, count);
        }
    }
    return res;
}