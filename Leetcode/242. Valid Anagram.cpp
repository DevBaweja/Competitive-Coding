#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    int n = s.size();
    unordered_map<char, int> m;
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
        m[t[i]]--;
    }
    for (pair<char, int> el : m)
        if (el.second)
            return false;
    return true;
}