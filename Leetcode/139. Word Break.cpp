#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    unordered_set<string> m;

    for (string el : wordDict)
        m.insert(el);

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j] && m.find(s.substr(j, i - j)) != m.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}