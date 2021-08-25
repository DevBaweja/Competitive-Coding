#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;
vector<int> v;

bool insert(int val)
{
    if (m.find(val) != m.end())
        return false;
    v.push_back(val);
    m[val] = v.size() - 1;
    return true;
}

bool remove(int val)
{
    if (m.find(val) == m.end())
        return false;
    int index = m[val];
    m.erase(val);
    int n = v.size();
    if (index == n - 1)
    {
        v.pop_back();
        return true;
    }
    v[index] = v[n - 1];
    v.pop_back();
    m[v[index]] = index;
    return true;
}

int getRandom()
{
    int r = rand() % v.size();
    return v[r];
}