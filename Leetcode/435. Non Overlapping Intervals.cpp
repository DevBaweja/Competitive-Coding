#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int end;
};

static int compare(Interval a, Interval b)
{
    if (a.end != b.end)
        return a.end < b.end;
    return a.start < b.start;
}

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<Interval> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].start = intervals[i][0];
        v[i].end = intervals[i][1];
    }

    sort(v.begin(), v.end(), compare);

    int i = 0;
    int res = 0;
    while (i < n)
    {
        Interval t = v[i];
        res++;
        i++;
        while (i < n && v[i].start < t.end)
            i++;
    }

    return n - res;
}
