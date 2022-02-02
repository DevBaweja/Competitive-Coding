#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// DP Full and Partial
int numTilings(int n)
{
    if (n == 1 || n == 2)
        return n;
    ll mod = 1e9 + 7;
    vector<ll> dpf(n + 1, 0);
    dpf[1] = 1;
    dpf[2] = 2;
    vector<ll> dpp(n + 1, 0);
    dpp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dpf[i] = dpf[i - 1] + dpf[i - 2] + dpp[i - 1];
        dpp[i] = 2 * dpf[i - 2] + dpp[i - 1];
        dpf[i] %= mod;
        dpp[i] %= mod;
    }
    return dpf[n];
}

// Space Optimized DP
int numTilings(int n)
{
    if (n == 1 || n == 2)
        return n;
    ll mod = 1e9 + 7;
    ll fullsingle = 1, fulldouble = 2;
    ll partial = 2;

    for (int i = 3; i <= n; i++)
    {
        ll fullnext = fulldouble + fullsingle + partial;
        ll partialnext = 2 * fullsingle + partial;
        fullnext %= mod;
        partialnext %= mod;
        fullsingle = fulldouble;
        fulldouble = fullnext;
        partial = partialnext;
    }
    return fulldouble;
}

// Matrix Exponentiation
vector<vector<ll>> matrix(vector<vector<ll>> &a, vector<vector<ll>> &b, int p, int q, int r, ll &mod)
{
    vector<vector<ll>> res(p, vector<ll>(r, 0));
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            ll sum = 0;
            for (int k = 0; k < q; k++)
            {
                sum += (a[i][k] * b[k][j]) % mod;
                sum %= mod;
            }
            res[i][j] = sum;
        }
    }
    return res;
}

int numTilings(int n)
{
    if (n == 1 || n == 2)
        return n;
    ll mod = 1e9 + 7;
    vector<vector<ll>> exp{{1, 1, 1}, {1, 0, 0}, {0, 2, 1}};
    vector<vector<ll>> res{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    int k = exp.size();
    int size = n - 2;
    while (size--)
        res = matrix(res, exp, k, k, k, mod);
    vector<vector<ll>> base{{2}, {1}, {2}};
    res = matrix(res, base, k, k, 1, mod);
    return res[0][0];
}