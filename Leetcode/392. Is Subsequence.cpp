#include <bits/stdc++.h>
using namespace std;

// DP
bool isSubsequence(string s, string t)
{
    int n = s.size(), m = t.size();
    if (n == 0)
        return true;
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
    for (int j = 0; j < m; j++)
        dp[0][j] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[n][m];
}

// Two Pointers
bool isSubsequence(string s, string t)
{
    int n = s.size(), m = t.size();

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            j++;
    }
    return i == n;
}

// Hashing and Indexing
int search(vector<int> v, int target)
{
    for (int i = 0; i < v.size(); i++)
        if (target <= v[i])
            return v[i];
    return -1;
}

bool isSubsequence(string s, string t)
{
    int n = s.size(), m = t.size();
    unordered_map<char, vector<int>> mp;
    for (int i = 0; i < m; i++)
    {
        char el = t[i];
        mp[el].push_back(i);
    }

    int target = 0;
    for (int i = 0; i < n; i++)
    {
        char el = s[i];
        if (mp.find(el) == mp.end())
            return false;
        int index = search(mp[el], target);
        if (index == -1)
            return false;
        target = index + 1;
    }
    return true;
}