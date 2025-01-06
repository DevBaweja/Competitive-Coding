#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    int buy = prices[0];
    int n = prices.size();
    for(int i=1; i<n; i++) {
        if(buy < prices[i]) {
            profit = max(profit, prices[i]-buy);
        }
        buy = min(buy, prices[i]);
    }
    return profit;
}

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