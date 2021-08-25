#include <bits/stdc++.h>
using namespace std;

// Using Stack
vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{

    stack<vector<int>> s;
    sort(intervals.begin(), intervals.end());
    for (vector<int> el : intervals)
    {
        if (s.empty() || el[0] > s.top()[1])
            s.push(el);
        else
        {
            vector<int> t = s.top();
            s.pop();
            t[1] = max(t[1], el[1]);
            s.push(t);
        }
    }

    int n = s.size();
    vector<vector<int>> res(n);
    int index = n - 1;
    while (!s.empty())
    {
        res[index--] = s.top();
        s.pop();
    }
    return res;
}

// Space - O(1)
vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
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

// Space - O(1)
vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{
    int index = 0;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= intervals[index][1])
            intervals[index][1] = max(intervals[index][1], intervals[i][1]);
        else
        {
            index++;
            swap(intervals[index], intervals[i]);
        }
    }

    intervals.resize(index + 1);
    return intervals;
}