#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DFS and DP
bool isSafe(int x, int y, int n, int m)
{
    bool valid = (x >= 0 && y >= 0 && x < n && y < m);
    bool number = (x == n - 1 && (y == 0 || y == m - 1));
    return valid && !number;
}

int dfs(int x, int y, int n, int m, int k, ll &mod, vector<vector<vector<ll>>> &dp)
{
    if (!isSafe(x, y, n, m))
        return 0;
    if (!k)
        return 1;
    if (dp[k - 1][x][y] != -1)
        return dp[k - 1][x][y];

    vector<int> dirx{-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> diry{1, 2, 2, 1, -1, -2, -2, -1};
    int count = 8;
    ll ans = 0;
    for (int ki = 0; ki < count; ki++)
    {
        int nx = x + dirx[ki];
        int ny = y + diry[ki];
        if (isSafe(nx, ny, n, m))
        {
            ans += dfs(nx, ny, n, m, k - 1, mod, dp);
            ans %= mod;
        }
    }
    return dp[k - 1][x][y] = ans;
}

int knightDialer(int k)
{
    int n = 4, m = 3;
    ll ans = 0;
    vector<vector<vector<ll>>> dp(k, vector<vector<ll>>(n, vector<ll>(m, -1)));
    ll mod = 1e9 + 7;
    k--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isSafe(i, j, n, m))
            {
                ans += dfs(i, j, n, m, k, mod, dp);
                ans %= mod;
            }
        }
    }
    return ans;
}

// DFS and DP
bool isSafe(int x, int y, int n, int m)
{
    bool valid = (x >= 0 && y >= 0 && x < n && y < m);
    bool number = (x == n - 1 && (y == 0 || y == m - 1));
    return valid && !number;
}

int dfs(int x, int y, int n, int m, int k, ll &mod, map<vector<int>, ll> &mp)
{
    if (!isSafe(x, y, n, m))
        return 0;
    if (!k)
        return 1;
    if (mp.find({k, x, y}) != mp.end())
        return mp[{k, x, y}];

    vector<int> dirx{-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> diry{1, 2, 2, 1, -1, -2, -2, -1};
    int count = 8;
    ll ans = 0;
    for (int ki = 0; ki < count; ki++)
    {
        int nx = x + dirx[ki];
        int ny = y + diry[ki];
        if (isSafe(nx, ny, n, m))
        {
            ans += dfs(nx, ny, n, m, k - 1, mod, mp);
            ans %= mod;
        }
    }
    return mp[{k, x, y}] = ans;
}

int knightDialer(int k)
{
    int n = 4, m = 3;
    ll ans = 0;
    ll mod = 1e9 + 7;
    k--;
    map<vector<int>, ll> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isSafe(i, j, n, m))
            {
                ans += dfs(i, j, n, m, k, mod, mp);
                ans %= mod;
            }
        }
    }
    return ans;
}

// DFS and DP
bool isSafe(int x, int y, int n, int m)
{
    bool valid = (x >= 0 && y >= 0 && x < n && y < m);
    bool number = (x == n - 1 && (y == 0 || y == m - 1));
    return valid && !number;
}

int dfs(int x, int y, int n, int m, int k, int &mod, vector<vector<vector<int>>> &dp, vector<int> &dirx, vector<int> &diry)
{
    if (!isSafe(x, y, n, m))
        return 0;
    if (!k)
        return 1;
    if (dp[k - 1][x][y] != -1)
        return dp[k - 1][x][y];
    int count = 8;
    int ans = 0;
    for (int ki = 0; ki < count; ki++)
    {
        int nx = x + dirx[ki];
        int ny = y + diry[ki];
        if (isSafe(nx, ny, n, m))
        {
            ans += dfs(nx, ny, n, m, k - 1, mod, dp, dirx, diry);
            ans %= mod;
        }
    }
    return dp[k - 1][x][y] = ans;
}

int knightDialer(int k)
{
    int n = 4, m = 3;
    int ans = 0;
    vector<vector<vector<int>>> dp(k, vector<vector<int>>(n, vector<int>(m, -1)));
    int mod = 1e9 + 7;
    k--;
    vector<int> dirx{-2, -1, 1, 2, 2, 1, -1, -2};
    vector<int> diry{1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isSafe(i, j, n, m))
            {
                ans += dfs(i, j, n, m, k, mod, dp, dirx, diry);
                ans %= mod;
            }
        }
    }
    return ans;
}

// DP
int knightDialer(int n)
{
    ll p0 = 1, p1 = 1, p2 = 1, p3 = 1, p4 = 1, p5 = 1, p6 = 1, p7 = 1, p8 = 1, p9 = 1;
    n--;
    ll mod = 1e9 + 7;
    while (n--)
    {
        ll n0 = p4 + p6;
        ll n1 = p6 + p8;
        ll n2 = p7 + p9;
        ll n3 = p4 + p8;
        ll n4 = p0 + p3 + p9;
        ll n5 = 0;
        ll n6 = p0 + p1 + p7;
        ll n7 = p2 + p6;
        ll n8 = p1 + p3;
        ll n9 = p2 + p4;
        p0 = n0 % mod;
        p1 = n1 % mod;
        p2 = n2 % mod;
        p3 = n3 % mod;
        p4 = n4 % mod;
        p5 = n5 % mod;
        p6 = n6 % mod;
        p7 = n7 % mod;
        p8 = n8 % mod;
        p9 = n9 % mod;
    }
    return (p0 + p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) % mod;
}

int knightDialer(int n)
{
    int size = 10;
    vector<int> dp(size, 1);
    n--;
    unordered_map<int, vector<int>> m = {
        {0, {4, 6}},
        {1, {6, 8}},
        {2, {7, 9}},
        {3, {4, 8}},
        {4, {0, 3, 9}},
        {5, {}},
        {6, {0, 1, 7}},
        {7, {2, 6}},
        {8, {1, 3}},
        {9, {2, 4}},
    };
    int mod = 1e9 + 7;
    while (n--)
    {
        vector<int> dn(size, 0);
        for (int index = 0; index < size; index++)
        {
            for (int el : m[index])
            {
                dn[index] = (dn[index] + dp[el]) % mod;
            }
        }
        dp = dn;
    }
    int res = 0;
    for (int el : dp)
        res = (res + el) % mod;
    return res;
}