#include <bits/stdc++.h>
#include <string.h>

using namespace std;

// String Sort
// Time- O(n*log(n))
// Space- O(1)
vector<int> lexicalOrder(int n)
{
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        v[i] = to_string(i + 1);
    sort(v.begin(), v.end());
    vector<int> r(n);
    for (int i = 0; i < n; i++)
        r[i] = stoi(v[i]);
    return r;
}

// Depth First Search
// Time- O(n)
// Space- O(1)
void traversal(int cur, int n, vector<int> &v)
{
    if (cur > n)
        return;
    v.push_back(cur);
    for (int next = 0; next <= 9; next++)
    {
        if (cur * 10 + next <= n)
            traversal(cur * 10 + next, n, v);
    }
}

vector<int> lexicalOrder(int n)
{
    vector<int> v;
    for (int cur = 1; cur <= 9; cur++)
        traversal(cur, n, v);
    return v;
}