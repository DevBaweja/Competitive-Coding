#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Tabular
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

// Tabular Space
ll countStrings(int n)
{
    int mod = 1e9 + 7;
    ll a = 1, b = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int temp = a;
        a = a + b;
        b = temp;
        a %= mod;
        b %= mod;
    }
    return (a + b) % mod;
}