#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    int pbuy = -prices[0], psell = 0;
    for (int i = 1; i < n; i++)
    {
        int nbuy = max(pbuy, psell - prices[i]);
        int nsell = max(pbuy + prices[i] - fee, psell);
        pbuy = nbuy;
        psell = nsell;
    }
    return max(pbuy, psell);
}