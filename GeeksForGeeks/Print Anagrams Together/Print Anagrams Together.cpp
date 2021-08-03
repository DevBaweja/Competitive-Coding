#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string> &list)
{
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;
    int n = list.size();
    for (string t : list)
    {
        string s = t;
        sort(s.begin(), s.end());
        m[s].push_back(t);
    }
    for (auto el : m)
        res.push_back(el.second);
    return res;
}