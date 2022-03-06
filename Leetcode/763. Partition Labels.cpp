#include <bits/stdc++.h>
using namespace std;

// Hashing and Merge Intervals
vector<int> partitionLabels(string s)
{
    unordered_map<int, int> m;
    int n = s.size();
    vector<pair<int, int>> v;
    for (int index = 0; index < n; index++)
    {
        char el = s[index];
        if (m.find(el) != m.end())
            v.push_back({m[el], index});
        else
        {
            v.push_back({index, index});
            m[el] = index;
        }
    }
    // Merge Intervals
    vector<int> res;
    sort(v.begin(), v.end());
    int k = v.size();
    int start = v[0].first;
    int end = v[0].second;
    for (int index = 1; index < k; index++)
    {
        int nextstart = v[index].first, nextend = v[index].second;
        if (nextstart <= end)
            end = max(end, nextend);
        else
        {
            res.push_back(end - start + 1);
            start = nextstart;
            end = nextend;
        }
    }
    res.push_back(end - start + 1);
    return res;
}