#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

static bool compare(Interval i1, Interval i2)
{
    if (i1.start == i2.start)
        return i1.end < i2.end;
    return i1.start < i2.start;
}

bool canAttendMeetings(vector<Interval> &intervals)
{
    int n = intervals.size();
    if (!n)
        return true;
    sort(intervals.begin(), intervals.end(), compare);
    int start = intervals[0].start;
    int end = intervals[0].end;
    for (int index = 1; index < n; index++)
    {
        Interval cur = intervals[index];
        if (cur.start < end)
            return false;
        start = cur.start;
        end = cur.end;
    }
    return true;
}