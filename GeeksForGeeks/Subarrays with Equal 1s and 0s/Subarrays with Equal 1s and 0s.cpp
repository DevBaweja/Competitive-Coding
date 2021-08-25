#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    unordered_map<lli, lli> m;
    m[0] = 1;
    lli sum = 0;
    lli res = 0;
    for (int i = 0; i < n; i++)
    {
        int el = arr[i];
        if (el)
            sum++;
        else
            sum--;
        if (m.find(sum) != m.end())
            res += m[sum];
        m[sum]++;
    }
    return res;
}