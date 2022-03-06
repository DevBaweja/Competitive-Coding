#include <bits/stdc++.h>
using namespace std;

// Hashing Addition Function and Check
bool check(string s, string p)
{
    sort(s.begin(), s.end());
    sort(p.begin(), p.end());

    return s == p;
}
bool check(string s, string p)
{
    int len = 26;
    vector<int> v(len, 0);
    for (char el : s)
        v[el - 'a']++;
    for (char el : p)
        v[el - 'a']--;
    for (int i = 0; i < len; i++)
        if (v[i])
            return false;
    return true;
}
vector<int> findAnagrams(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<int> res;
    if (n < m)
        return res;

    int cv = 0;
    int rv = 0;
    for (char el : p)
        rv += el - 'a' + 1;

    for (int i = 0; i < m; i++)
        cv += s[i] - 'a' + 1;

    if (cv == rv && check(s.substr(0, m), p))
        res.push_back(0);

    for (int i = m; i < n; i++)
    {
        cv -= s[i - m] - 'a' + 1;
        cv += s[i] - 'a' + 1;
        if (cv == rv && check(s.substr(i - m + 1, m), p))
            res.push_back(i - m + 1);
    }
    return res;
}

// Hashing and Sliding Window
bool check(unordered_map<char, int> &ms, unordered_map<char, int> &mp)
{
    if (ms.size() != mp.size())
        return false;
    for (pair<char, int> s : ms)
        if (mp.find(s.first) == mp.end() || mp[s.first] != s.second)
            return false;
    return true;
}

vector<int> findAnagrams(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<int> res;
    if (n < m)
        return res;

    unordered_map<char, int> ms, mp;
    for (char el : p)
        mp[el]++;

    for (int i = 0; i < m; i++)
        ms[s[i]]++;

    if (check(ms, mp))
        res.push_back(0);

    for (int i = m; i < n; i++)
    {

        char release = s[i - m];
        ms[release]--;
        if (!ms[release])
            ms.erase(release);
        char acquire = s[i];
        ms[acquire]++;
        if (check(ms, mp))
            res.push_back(i - m + 1);
    }
    return res;
}

// Optimized Bad Variable Count
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

vector<int> findAnagrams(string s, string p)
{
    int n = s.size();
    int m = p.size();
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
        res.push_back(0);

    for (int i = m; i < n; i++)
    {
        add(s[i], bad, mp);
        rem(s[i - m], bad, mp);
        if (!bad)
            res.push_back(i - m + 1);
    }
    return res;
}

// Optimized Count Hashing and Sliding Window
vector<int> findAnagrams(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<int> res;
    if (n < m)
        return res;
    int count = 0;
    unordered_map<char, int> ms, mp;
    for (char el : p)
        mp[el]++;

    for (int i = 0; i < m; i++)
    {
        int acquire = s[i];
        if (mp.find(acquire) != mp.end() && ms[acquire] == mp[acquire])
            count--;
        ms[acquire]++;
        if (mp.find(acquire) != mp.end() && ms[acquire] == mp[acquire])
            count++;
    }

    if (count == mp.size())
        res.push_back(0);

    for (int i = m; i < n; i++)
    {
        char release = s[i - m];
        if (mp.find(release) != mp.end() && ms[release] == mp[release])
            count--;
        ms[release]--;
        if (mp.find(release) != mp.end() && ms[release] == mp[release])
            count++;
        if (!ms[release])
            ms.erase(release);
        char acquire = s[i];
        if (mp.find(acquire) != mp.end() && ms[acquire] == mp[acquire])
            count--;
        ms[acquire]++;
        if (mp.find(acquire) != mp.end() && ms[acquire] == mp[acquire])
            count++;
        if (count == mp.size())
            res.push_back(i - m + 1);
    }
    return res;
}