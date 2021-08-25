#include <bits/stdc++.h>
using namespace std;

// Two Traversal and Hashing
char nonrepeatingCharacter(string s)
{
    unordered_map<char, int> m;
    for (char el : s)
        m[el]++;
    for (char el : s)
        if (m[el] == 1)
            return el;
    return '$';
}

// One Traversal and Hashing
char nonrepeatingCharacter(string s)
{
    unordered_map<char, pair<int, int>> m;
    for (int i = 0; i < s.size(); i++)
    {
        if (m.find(s[i]) == m.end())
            m[s[i]] = {0, i};
        m[s[i]].first++;
    }

    int res = INT_MAX;
    for (pair<char, pair<int, int>> p : m)
    {
        if (p.second.first == 1)
            res = min(res, p.second.second);
    }
    return res == INT_MAX ? '$' : s[res];
}