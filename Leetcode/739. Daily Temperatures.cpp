#include <bits/stdc++.h>
using namespace std;

// Stack
vector<int> dailyTemperatures(vector<int> &T)
{
    vector<int> v(T.size());
    stack<int> s;

    for (int i = T.size() - 1; i >= 0; --i)
    {
        while (!s.empty() && T[i] >= T[s.top()])
            s.pop();

        v[i] = s.empty() ? 0 : s.top() - i;
        s.push(i);
    }

    return v;
}

// Monotonic stack
vector<int> dailyTemperatures(vector<int> &temp)
{
    int n = temp.size();
    stack<pair<int, int>> s;
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int el = temp[i];
        while (!s.empty() && el >= s.top().first)
            s.pop();
        if (s.empty())
            ans[i] = 0;
        else
            ans[i] = s.top().second - i;
        s.push({el, i});
    }
    return ans;
}