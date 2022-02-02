#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DP
int countVowelPermutation(int n)
{
    ll a = 1, e = 1, i = 1, o = 1, u = 1;
    ll mod = 1e9 + 7;
    n--;
    while (n--)
    {
        ll na = u + i + e;
        ll ne = i + a;
        ll ni = o + e;
        ll no = i;
        ll nu = o + i;
        na %= mod;
        ne %= mod;
        ni %= mod;
        no %= mod;
        nu %= mod;
        a = na;
        e = ne;
        i = ni;
        o = no;
        u = nu;
    }
    return (a + e + i + o + u) % mod;
}

// TODO
// Matrix Exponentiation