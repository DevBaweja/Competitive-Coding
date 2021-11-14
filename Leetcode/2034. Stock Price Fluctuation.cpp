#include <bits/stdc++.h>
using namespace std;

class StockPrice
{
public:
    map<int, int> m;
    StockPrice()
    {
    }

    void update(int time, int price)
    {
        m[time] = price;
    }

    int current()
    {
        return (--m.end())->second;
    }

    int maximum()
    {
        int maxi = INT_MIN;
        for (pair<int, int> p : m)
            maxi = max(maxi, p.second);
        return maxi;
    }

    int minimum()
    {
        int mini = INT_MAX;
        for (pair<int, int> p : m)
            mini = min(mini, p.second);
        return mini;
    }
};