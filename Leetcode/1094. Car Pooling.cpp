#include <bits/stdc++.h>
using namespace std;

// Greedy
bool carPooling(vector<vector<int>> &trips, int cap)
{
    int n = trips.size();
    vector<pair<int, int>> info;
    for (vector<int> trip : trips)
    {
        int pass = trip[0], from = trip[1], to = trip[2];
        info.push_back({from, pass});
        info.push_back({to, -pass});
    }
    sort(info.begin(), info.end());
    int cur = 0;
    for (pair<int, int> p : info)
    {
        int pass = p.second;
        cur += pass;
        if (cur > cap)
            return false;
    }
    return true;
}

// Filling with negative and Prefix Sum
bool carPooling(vector<vector<int>> &trips, int cap)
{
    int k = 1e3;
    vector<int> info(k + 1, 0);

    for (vector<int> trip : trips)
    {
        int pass = trip[0], from = trip[1], to = trip[2];
        info[from] += pass;
        info[to] -= pass;
    }

    int cur = 0;
    for (int el : info)
    {
        cur += el;
        if (cur > cap)
            return false;
    }
    return true;
}