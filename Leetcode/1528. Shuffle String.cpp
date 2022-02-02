#include <bits/stdc++.h>
using namespace std;

// Hashing
string restoreString(string s, vector<int> &r)
{
    int n = s.size();
    vector<char> v(n);
    unordered_map<int, char> m;
    for (int i = 0; i < n; i++)
        m[r[i]] = s[i];
    for (pair<int, int> p : m)
        v[p.first] = p.second;
    string res = "";
    for (char el : v)
        res += el;
    return res;
}

// Brute Force
string restoreString(string s, vector<int> &r)
{
    int n = s.size();
    vector<char> v(n);
    for (int i = 0; i < n; i++)
        v[r[i]] = s[i];
    string res = "";
    for (char el : v)
        res += el;
    return res;
}

// Cyclic Sort
string restoreString(string s, vector<int> &r)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        while (r[i] != i)
        {
            swap(s[i], s[r[i]]);
            swap(r[i], r[r[i]]);
        }
    }
    return s;
}
// Do it untill current position is satisfied
// With every swap an letter is placed at correct position