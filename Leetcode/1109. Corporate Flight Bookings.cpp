#include <bits/stdc++.h>
using namespace std;

// Brute Force
vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> res(n, 0);
    for (vector<int> &el : bookings)
    {
        int u = el[0] - 1, v = el[1] - 1, cost = el[2];
        for (int k = u; k <= v; k++)
            res[k] += cost;
    }
    return res;
}

// Prefix Sum and Negative Insertion
vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> res(n, 0);
    for (vector<int> &el : bookings)
    {
        int u = el[0] - 1, v = el[1], cost = el[2];
        res[u] += cost;
        if (v != n)
            res[v] += -cost;
    }

    for (int i = 1; i < n; i++)
        res[i] += res[i - 1];
    return res;
}