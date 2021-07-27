#include <bits/stdc++.h>
using namespace std;

// Hashing
bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> mp;
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++)
        mp[arr[i]]++;

    for (auto itr : mp)
    {
        auto p = s.insert(itr.second);
        if (!p.second)
            return false;
    }
    return true;
}