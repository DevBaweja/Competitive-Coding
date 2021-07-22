#include <bits/stdc++.h>
using namespace std;

// Hashing and DP
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> m;
    int res = 0, cur = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (m.find(s[i]) != m.end())
            cur = min(cur + 1, i - m[s[i]]);
        else
            cur++;
        res = max(res, cur);
        m[s[i]] = i;
    }
    return res;
}