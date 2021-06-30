#include <bits/stdc++.h>
using namespace std;

string getPattern(string pattern)
{
    string res = "";
    map<char, int> m;
    int index = 1;
    for (char el : pattern)
    {
        if (m.find(el) == m.end())
            m[el] = index++;
        res += to_string(m[el]);
    }
    return res;
}

vector<string> findMatchedWords(vector<string> dict, string pattern)
{
    vector<string> res;
    string p = getPattern(pattern);
    for (string el : dict)
    {
        string pi = getPattern(el);
        if (p == pi)
            res.push_back(el);
    }
    return res;
}