#include <bits/stdc++.h>
using namespace std;

// Greedy
int maxCoins(vector<int> &piles)
{
    int n = piles.size();
    sort(piles.begin(), piles.end());
    int res = 0;
    for (int i = n - 2; i >= n / 3; i -= 2)
        res += piles[i];
    return res;
}