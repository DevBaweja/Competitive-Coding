#include <bits/stdc++.h>
using namespace std;

// Iterative
int count(int n)
{
    int c = 0;
    while (n != 1)
    {
        if (n & 1)
            n = 3 * n + 1;
        else
            n = n / 2;
        c++;
    }
    return c;
}

// Recursive
int count(int n)
{
    if (n == 1)
        return n;
    if (n & 1)
        return 1 + count(3 * n + 1);
    return 1 + count(n / 2);
}

int getKth(int low, int high, int k)
{
    vector<pair<int, int>> res;
    for (int index = low; index <= high; index++)
        res.push_back({count(index), index});
    sort(res.begin(), res.end());
    return res[k - 1].second;
}

// DP
int count(int n, unordered_map<int, int> &m)
{
    if (n == 1)
        return n;
    if (m.find(n) != m.end())
        return m[n];
    if (n & 1)
        return m[n] = 1 + count(3 * n + 1, m);
    return m[n] = 1 + count(n / 2, m);
}

int getKth(int low, int high, int k)
{
    vector<pair<int, int>> res;
    unordered_map<int, int> m;

    for (int index = low; index <= high; index++)
        res.push_back({count(index, m), index});
    sort(res.begin(), res.end());
    return res[k - 1].second;
}

// TODO
// Graph Topological Sort