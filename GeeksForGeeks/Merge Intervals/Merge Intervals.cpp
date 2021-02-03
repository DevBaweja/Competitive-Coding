#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct Interval
{
    int start, end;
};

bool compareInterval(Interval x, Interval y)
{
    return x.start < y.start;
}

stack<Interval> mergeIntervals(Interval I[], int n)
{
    stack<Interval> s;

    sort(I, I + n, compareInterval);

    s.push(I[0]);

    for (int i = 1; i < n; i++)
    {

        Interval top = s.top();
        if (top.end < I[i].start)
            s.push(I[i]);
        else if (top.end < I[i].end)
            top.end = I[i].end;
    }

    return s;
}
// Time- O(n*log(n))
// Space- O(n) for stack

void mergeIntervalsInPlace(Interval I[], int n)
{
    sort(I, I + n, compareInterval);

    int current = 0;

    for (int index = 1; index < n; index++)
    {
        if (I[current].end >= I[index].start)
            I[current].end = max(I[current].end, I[index].end);
        else
        {
            current++;
            I[current] = I[index];
        }
    }

    for (int i = 0; i <= current; i++)
        cout << I[i].start << " " << I[i].end << endl;
}

int main()
{
    Interval I[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = 4;

    /*
    stack<Interval> s = mergeIntervals(I, n);

    while (!s.empty())
    {
        Interval i = s.top();
        cout << i.start << " " << i.end << endl;
        s.pop();
    }
    */

    mergeIntervalsInPlace(I, n);
    return 0;
}