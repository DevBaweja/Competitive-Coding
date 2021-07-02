#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countStrings(int n)
{
    vector<ll> a(n + 1, 0);
    vector<ll> b(n + 1, 0);
    int mod = 1e9 + 7;
    a[1] = 1;
    b[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = (a[i - 1] % mod + b[i - 1] % mod) % mod;
        b[i] = a[i - 1];
    }
    return (a[n] + b[n]) % mod;
}