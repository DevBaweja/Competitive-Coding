#include <bits/stdc++.h>
using namespace std;

struct Envelope
{
    int width;
    int height;
};

bool compare(Envelope a, Envelope b)
{
    return a.width < b.width;
}

int main()
{
    int n;
    cin >> n;
    vector<Envelope> e(n);
    for (int i = 0; i < n; i++)
        cin >> e[i].width >> e[i].height;

    sort(e.begin(), e.end(), compare);
    int res = 1;
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
    cout << res;
}