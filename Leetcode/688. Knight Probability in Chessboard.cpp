#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n)
{
    return (x >= 0 && y >= 0 && x < n && y < n);
}

double power(int a, int b)
{
    if (!b)
        return 1;
    double p = power(a, b / 2);
    if (b & 1)
        return p * a * p;
    return p * p;
}

double knightProbability(int n, int k, int r, int c)
{
    if (!k)
        return 1.0;
    queue<pair<pair<int, int>, double>> q;
    q.push({{r, c}, 1.0});
    int t = k;
    while (t--)
    {
        int size = q.size();
        vector<vector<double>> dp(n, vector<double>(n, 0.0));

        while (size--)
        {
            pair<pair<int, int>, double> p = q.front();
            q.pop();
            int curx = p.first.first;
            int cury = p.first.second;
            double step = p.second;
            int count = 8;
            vector<int> dirx{-2, -1, 1, 2, 2, 1, -1, -2};
            vector<int> diry{1, 2, 2, 1, -1, -2, -2, -1};
            for (int k = 0; k < count; k++)
            {
                int nextx = curx + dirx[k];
                int nexty = cury + diry[k];
                if (isSafe(nextx, nexty, n))
                    dp[nextx][nexty] += step;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dp[i][j])
                    q.push({{i, j}, dp[i][j]});
    }
    double count = 0.0;
    while (!q.empty())
    {
        pair<pair<int, int>, double> p = q.front();
        q.pop();
        count += p.second;
    }
    double power = pow(8, k);
    return count / power;
}