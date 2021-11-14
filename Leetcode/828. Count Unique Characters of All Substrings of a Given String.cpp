#include <bits/stdc++.h>
using namespace std;

// Brute Force
int uniqueLetterString(string s)
{
    int n = s.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> m;
        int count = 0;
        for (int j = i; j < n; j++)
        {
            if (m.find(s[j]) == m.end())
                count++;
            else if (m[s[j]] == 1)
                count--;
            m[s[j]]++;

            ans += count;
        }
    }
    return ans;
}

// Left and Right DP
int uniqueLetterString(string s)
{
    int n = s.size();
    vector<int> dpl(n, -1);
    vector<int> dpr(n, -1);
    unordered_map<char, int> ml, mr;

    for (int i = 0; i < n; i++)
    {
        if (ml.find(s[i]) != ml.end())
            dpl[i] = ml[s[i]];
        ml[s[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (mr.find(s[i]) != mr.end())
            dpr[i] = mr[s[i]];
        mr[s[i]] = i;
    }
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int l = dpl[i];
        int r = dpr[i];
        if (l == -1)
            l = i;
        else
            l = i - l - 1;
        if (r == -1)
            r = n - i - 1;
        else
            r = r - i - 1;
        ans += (l + 1) * (r + 1);
    }
    return ans;
}