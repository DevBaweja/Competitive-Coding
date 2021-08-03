#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;
    for (string t : strs)
    {
        string s = t;
        sort(s.begin(), s.end());
        m[s].push_back(t);
    }
    for (auto t : m)
        res.push_back(t.second);
    return res;
}