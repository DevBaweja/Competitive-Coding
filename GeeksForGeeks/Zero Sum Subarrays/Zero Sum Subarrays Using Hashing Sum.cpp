#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll findSubarray(vector<ll> arr, int n)
{
    unordered_map<ll, ll> m;
    m[0] = 1;
    ll sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (m.find(sum) != m.end())
            count += m[sum];
        m[sum]++;
    }
    return count;
}