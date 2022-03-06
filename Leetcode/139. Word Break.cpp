#include <bits/stdc++.h>
using namespace std;

// DP
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

// DP
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> st;
    for (string word : wordDict)
        st.insert(word);
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            string cand = s.substr(j, i - j);
            if (st.find(cand) != st.end() && dp[j])
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}