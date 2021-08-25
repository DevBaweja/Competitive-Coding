#include <bits/stdc++.h>
using namespace std;

struct Bridge
{
    int north;
    int south;
};

bool compare(Bridge a, Bridge b)
{
    if (a.north != b.north)
        return a.north < b.north;
    return a.south < b.south;
}

int main()
{
    int n;
    cin >> n;
    vector<Bridge> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i].north >> A[i].south;

    sort(A.begin(), A.end(), compare);

    vector<int> dp(n, 0);
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        int maxi = 0;
        for (int j = 0; j < i; j++)
        {
            if (A[j].south <= A[i].south)
                maxi = max(maxi, dp[j]);
        }
        dp[i] = maxi + 1;
        res = max(res, dp[i]);
    }
    cout << res;
}