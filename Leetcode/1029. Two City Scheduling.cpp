#include <bits/stdc++.h>
using namespace std;

static bool compare(vector<int> a, vector<int> b)
{
    return (a[0] - b[0]) < (a[1] - b[1]);
}

int twoCitySchedCost(vector<vector<int>> &costs)
{
    int n = costs.size();
    sort(costs.begin(), costs.end(), compare);
    int cost = 0;
    for (int i = 0; i < n / 2; i++)
        cost += costs[i][0];
    for (int i = n / 2; i < n; i++)
        cost += costs[i][1];
    return cost;
}