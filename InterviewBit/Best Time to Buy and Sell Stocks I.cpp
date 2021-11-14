#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &prices)
{
    int n = prices.size();
    if (!n)
        return 0;
    int buy = INT_MAX;
    int profit = 0;
    for (int sell : prices)
    {
        buy = min(buy, sell);
        profit = max(profit, sell - buy);
    }
    return profit;
}
