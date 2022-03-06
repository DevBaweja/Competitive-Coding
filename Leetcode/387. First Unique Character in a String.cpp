#include <bits/stdc++.h>
using namespace std;

// Hashing
int firstUniqChar(string s)
{
    unordered_map<char, int> m;
    for (char el : s)
        m[el]++;
    for (int i = 0; i < s.size(); i++)
    {
        char el = s[i];
        if (m[el] == 1)
            return i;
    }
    return -1;
}

// Space Optimized
int firstUniqChar(string s)
{
    int size = 26;
    int n = s.size();
    vector<int> v(size, 0);
    for (char el : s)
        v[el - 'a']++;
    for (int i = 0; i < n; i++)
        if (v[s[i] - 'a'] == 1)
            return i;
    return -1;
}

// Two Loop Optimized
int firstUniqChar(string s)
{
    int size = 26;
    int n = s.size();
    vector<pair<int, int>> v(size, {0, n});
    for (int i = 0; i < n; i++)
    {
        int el = s[i] - 'a';
        v[el].first++;
        if (v[el].second == n)
            v[el].second = i;
    }
    int res = n;
    for (pair<int, int> p : v)
        if (p.first == 1)
            res = min(res, p.second);

    return res == n ? -1 : res;
}
