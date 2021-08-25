#include <bits/stdc++.h>
using namespace std;

void add(char el, int &bad, unordered_map<char, int> &mp)
{
    mp[el]--;
    if (mp[el] == 0)
        bad--;
    if (mp[el] == -1)
        bad++;
}

void rem(char el, int &bad, unordered_map<char, int> &mp)
{
    mp[el]++;
    if (mp[el] == 0)
        bad--;
    if (mp[el] == 1)
        bad++;
}

bool checkInclusion(string p, string s)
{

    int n = s.size();
    int m = p.size();
    if (m > n)
        return false;
    unordered_map<char, int> mp;
    int bad = 0;
    for (int i = 0; i < m; i++)
    {
        char el = p[i];
        mp[el]++;
        if (mp[el] == 1)
            bad++;
    }
    for (int i = 0; i < m; i++)
        add(s[i], bad, mp);

    vector<int> res;
    if (!bad)
        return true;

    for (int i = m; i < n; i++)
    {
        add(s[i], bad, mp);
        rem(s[i - m], bad, mp);
        if (!bad)
            return true;
    }
    return false;
}