#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(ll x, ll n, ll mod)
{
    if (!n)
        return 1ll;
    ll temp = power(x, n / 2, mod);
    if (n & 1ll)
        return (temp * x * temp) % mod;
    return (temp * temp) % mod;
}
int countGoodNumbers(ll n)
{
    ll mod = 1e9 + 7;
    return (power(4ll, n / 2, mod) * power(5ll, n - n / 2, mod)) % mod;
}