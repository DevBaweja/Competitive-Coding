#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    int n = intervals.size();

    sort(intervals.begin(), intervals.end());
    int l = intervals[0][0];
    int r = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= r)
            r = max(r, intervals[i][1]);
        else
        {
            res.push_back({l, r});
            l = intervals[i][0];
            r = intervals[i][1];
        }
    }
    res.push_back({l, r});
    return res;
}