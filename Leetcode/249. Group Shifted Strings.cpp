#include <bits/stdc++.h>
using namespace std;

// Hashing
vector<vector<string>> groupStrings(vector<string> &s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int alpha = 26;
    unordered_map<string, vector<string>> m;
    for (string el : s)
    {
        string t = "";
        if (el.size() != 1)
        {
            for (int i = 1; i < el.size(); i++)
            {
                int diff = el[i] - el[i - 1];
                if (diff < 0)
                    diff += alpha;
                t += (diff + 'a');
            }
        }
        m[t].push_back(el);
    }
    vector<vector<string>> res;
    for (pair<string, vector<string>> p : m)
        res.push_back(p.second);
    return res;
}