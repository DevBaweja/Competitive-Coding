#include <bits/stdc++.h>
using namespace std;

int maxTwoEvents(vector<vector<int>> &events)
{
    sort(events.begin(), events.end());
    int maxi = INT_MIN;
    for (vector<int> event : events)
        maxi = max(maxi, event[2]);

    int n = events.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int prevEnd = events[i][1];
            int nextStart = events[j][0];
            if (prevEnd < nextStart)
                maxi = max(maxi, events[i][2] + events[j][2]);
        }
    }
    return maxi;
}