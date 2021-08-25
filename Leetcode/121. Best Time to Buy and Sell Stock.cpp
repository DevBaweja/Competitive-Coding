#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int buy = INT_MAX, profit = 0;
    for (int sell : prices)
    {
        buy = min(buy, sell);
        profit = max(profit, sell - buy);
    }
    return profit;
}