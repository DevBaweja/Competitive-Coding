#include <bits/stdc++.h>
using namespace std;

// Circular Motion
vector<int> mostVisited(int n, vector<int> &rounds)
{
    int m = rounds.size();
    map<int, int> mp;
    int maxi = INT_MIN;
    int start = rounds[0] - 1;
    for (int i = 1; i < m; i++)
    {
        int end = rounds[i] - 1;
        while (start != end)
        {
            mp[start]++;
            maxi = max(maxi, mp[start]);
            start++;
            start %= n;
        }
        start = end;
    }
    mp[start]++;
    maxi = max(maxi, mp[start]);

    vector<int> res;
    for (pair<int, int> p : mp)
        if (maxi == p.second)
            res.push_back(p.first + 1);
    return res;
}
