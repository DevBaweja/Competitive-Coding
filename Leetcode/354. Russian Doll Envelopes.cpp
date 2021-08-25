#include <bits/stdc++.h>
using namespace std;

struct Envelope
{
    int width;
    int height;
};

static bool compare(Envelope a, Envelope b)
{
    if (a.width != b.width)
        return a.width < b.width;
    return a.height < b.height;
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    int n = envelopes.size();
    vector<Envelope> e(n);
    for (int i = 0; i < n; i++)
    {
        e[i].width = envelopes[i][0];
        e[i].height = envelopes[i][1];
    }

    sort(e.begin(), e.end(), compare);

    int res = 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int maxi = 0;
        for (int j = 0; j < i; j++)
        {
            if (e[j].height < e[i].height && e[j].width < e[i].width)
                maxi = max(maxi, dp[j]);
        }
        dp[i] = maxi + 1;
        res = max(res, dp[i]);
    }
    return res;
}