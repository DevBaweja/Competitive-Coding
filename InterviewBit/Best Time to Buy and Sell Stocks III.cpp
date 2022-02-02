#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &price)
{
    int n = price.size();
    if (n == 0 || n == 1)
        return 0;
    int buy = price[0];
    vector<int> dpsell(n, 0);
    for (int i = 1; i < n; i++)
    {
        int sell = price[i];
        dpsell[i] = max(dpsell[i - 1], sell - buy);
        buy = min(buy, sell);
    }
    vector<int> dpbuy(n, 0);
    int sell = price[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int buy = price[i];
        dpbuy[i] = max(dpbuy[i + 1], sell - buy);
        sell = max(sell, buy);
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, dpbuy[i] + dpsell[i]);
    return maxi;
}