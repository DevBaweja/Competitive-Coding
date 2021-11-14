#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int isSafe(int x, int y, int n)
{
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int r, c;
    cin >> r >> c;

    queue<pair<pair<int, int>, ll>> q;
    q.push({{r, c}, 1});
    int t = k;
    while (t--)
    {
        int count = q.size();
        vector<vector<ll>> dp(n, vector<ll>(n, 0ll));
        while (count--)
        {
            pair<pair<int, int>, ll> p = q.front();
            q.pop();
            int curx = p.first.first;
            int cury = p.first.second;
            ll val = p.second;
            vector<int> dirx{1, 2, 2, 1, -1, -2, -2, -1};
            vector<int> diry{2, 1, -1, -2, -2, -1, 1, 2};
            int size = 8;
            for (int k = 0; k < size; k++)
            {
                int nextx = curx + dirx[k];
                int nexty = cury + diry[k];
                if (isSafe(nextx, nexty, n))
                    dp[nextx][nexty] += val;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dp[i][j])
                    q.push({{i, j}, dp[i][j]});
    }

    ll res = 0;
    while (!q.empty())
    {
        pair<pair<int, int>, ll> p = q.front();
        q.pop();
        res += p.second;
    }
    ll power = pow(8, k);
    long double ans = (long double)res / power;

    cout << setprecision(17) << ans;
    return 0;
}