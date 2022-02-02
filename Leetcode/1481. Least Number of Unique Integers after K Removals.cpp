#include <bits/stdc++.h>
using namespace std;

int findLeastNumOfUniqueInts(vector<int> &arr, int k)
{
    unordered_map<int, int> m;
    for (int el : arr)
        m[el]++;
    vector<pair<int, int>> v;
    for (pair<int, int> p : m)
        v.push_back({p.second, p.first});
    sort(v.begin(), v.end());
    int n = v.size();
    int index = 0;
    while (index < n && k && k >= v[index].first)
        k -= v[index++].first;
    unordered_set<int> s;
    while (index < n)
        s.insert(v[index++].second);
    return s.size();
}