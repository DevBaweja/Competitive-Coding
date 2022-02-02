#include <bits/stdc++.h>
using namespace std;

// Count and Hashing
int count(int n)
{
    int c = 0;
    while (n)
    {
        c += n & 1;
        n = n >> 1;
    }
    return c;
}

// Kernighan Algorithm
int count(int n)
{
    int c = 0;
    while (n)
    {
        int t = n & -n;
        n -= t;
        c++;
    }
    return c;
}

vector<int> sortByBits(vector<int> &arr)
{
    map<int, vector<int>> m;

    for (int el : arr)
        m[count(el)].push_back(el);

    vector<int> v;
    for (pair<int, vector<int>> p : m)
    {
        sort(p.second.begin(), p.second.end());
        for (int el : p.second)
            v.push_back(el);
    }
    return v;
}

// Count and Sorting Comparator
static int count(int n)
{
    int c = 0;
    while (n)
    {
        int t = n & -n;
        n -= t;
        c++;
    }
    return c;
}

static bool compare(int a, int b)
{
    int ta = count(a), tb = count(b);
    if (ta == tb)
        return a < b;
    return ta < tb;
}

vector<int> sortByBits(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), compare);
    return arr;
}