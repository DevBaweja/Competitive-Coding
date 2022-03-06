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

// Map and Vector, Swap and Pop back
vector<int> v;
unordered_map<int, int> m;

bool insert(int val)
{
    if (m.find(val) != m.end())
        return false;
    m[val] = v.size();
    v.push_back(val);
    return true;
}

bool remove(int val)
{
    if (m.find(val) == m.end())
        return false;
    int index = m[val];
    swap(v[index], v[v.size() - 1]);
    v.pop_back();
    if (v.size())
        m[v[index]] = index;
    m.erase(val);

    return true;
}

int getRandom()
{
    int r = rand() % v.size();
    return v[r];
}

// Optimized
vector<int> v;
unordered_map<int, int> m;

bool insert(int val)
{
    if (m.find(val) != m.end())
        return false;
    m[val] = v.size();
    v.push_back(val);
    return true;
}

bool remove(int val)
{
    if (m.find(val) == m.end())
        return false;
    int index = m[val];
    m.erase(val);
    if (index == v.size() - 1)
    {
        v.pop_back();
        return true;
    }
    swap(v[index], v[v.size() - 1]);
    v.pop_back();
    m[v[index]] = index;
    return true;
}

int getRandom()
{
    int r = rand() % v.size();
    return v[r];
}