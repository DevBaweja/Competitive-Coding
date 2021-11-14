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

// Hashing and Sliding Window
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    if (!n)
        return 0;
    unordered_map<char, int> m;
    int low = 0;
    int res = 1;
    int count = 0;
    for (int high = 0; high < n; high++)
    {
        char acquire = s[high];
        if (m[acquire] == 1)
            count++;
        m[acquire]++;

        if (!count)
            res = max(res, high - low + 1);

        while (low <= high && count)
        {
            char release = s[low];
            m[release]--;
            if (m[release] == 1)
                count--;
            low++;
        }
    }

    return res;
}

// Hashing
int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    if (!n)
        return n;

    int low = 0;
    unordered_set<char> m;
    int ans = INT_MIN;

    for (int high = 0; high < s.length(); high++)
    {
        if (m.find(s[high]) == m.end())
        {
            m.insert(s[high]);
            ans = max(ans, high - low + 1);
        }
        else
        {
            while (s[low] != s[high])
            {
                m.erase(s[low]);
                low++;
            }
            low++;
        }
    }

    if (ans == INT_MIN)
        return 0;
    return ans;
}