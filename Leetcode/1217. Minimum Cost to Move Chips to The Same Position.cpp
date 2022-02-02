#include <bits/stdc++.h>
using namespace std;

int minCostToMoveChips(vector<int> &position)
{
    int even = 0, odd = 0;
    for (int el : position)
    {
        if (el & 1)
            odd++;
        else
            even++;
    }
    return min(odd, even);
}