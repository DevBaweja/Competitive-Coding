#include <bits/stdc++.h>
using namespace std;

int eliminateMaximum(vector<int> &dist, vector<int> &speed)
{
    int n = dist.size();
    vector<int> time(n);
    for (int i = 0; i < n; i++)
        time[i] = dist[i] / speed[i] + (dist[i] % speed[i] ? 1 : 0);
    sort(time.begin(), time.end());

    for (int i = 0; i < n; i++)
        if (i >= time[i])
            return i;
    return n;
}