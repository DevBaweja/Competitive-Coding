#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DFS
int dfs(unordered_map<int, vector<int>> &m, int el)
{
    if (m.find(el) == m.end())
        return 1;
    vector<int> v = m[el];
    int count = 1;
    for (int el : v)
        count += dfs(m, el);
    return count;
}

int countHighestScoreNodes(vector<int> &parents)
{
    int n = parents.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
        m[parents[i]].push_back(i);

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ll cur = 1;
        if (m.find(i) != m.end())
        {
            vector<int> v = m[i];
            vector<int> count;
            for (int el : v)
                count.push_back(dfs(m, el));
            ll sum = 0;

            for (int el : count)
            {
                cur *= el;
                sum += el;
            }

            int rem = n - sum - 1;
            if (rem)
                cur *= rem;
        }
        else
            cur = n - 1;
        ans.push_back(cur);
    }
    ll res = *max_element(ans.begin(), ans.end());
    return count(ans.begin(), ans.end(), res);
}

//  DFS with DP
ll dfs(unordered_map<int, vector<int>> &m, int el, vector<ll> &dp)
{
    if (dp[el] != -1)
        return dp[el];
    if (m.find(el) == m.end())
        return 1;
    vector<int> v = m[el];
    ll count = 1;
    for (int el : v)
        count += dfs(m, el, dp);
    dp[el] = count;
    return count;
}

int countHighestScoreNodes(vector<int> &parents)
{
    int n = parents.size();
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
        m[parents[i]].push_back(i);

    vector<ll> ans;
    vector<ll> dp(n, -1);
    for (int i = 0; i < n; i++)
    {
        ll cur = 1;
        if (m.find(i) != m.end())
        {
            vector<int> v = m[i];
            vector<ll> count;
            for (int el : v)
                count.push_back(dfs(m, el, dp));
            ll sum = 0;

            for (ll el : count)
            {
                cur *= el;
                sum += el;
            }

            ll rem = n - sum - 1;
            if (rem)
                cur *= rem;
        }
        else
            cur = n - 1;
        ans.push_back(cur);
    }
    ll res = *max_element(ans.begin(), ans.end());
    return count(ans.begin(), ans.end(), res);
}