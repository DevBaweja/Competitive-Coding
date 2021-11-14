#include <bits/stdc++.h>
using namespace std;

// Iterative
string fn(string s)
{
    string r = "";
    for (char ch : s)
        r += (ch == '0' ? '1' : '0');
    reverse(r.begin(), r.end());
    return r;
}

char findKthBit(int n, int k)
{
    string s = "0";
    while (n--)
        s = s + "1" + fn(s);
    return s[k - 1];
}

// Recursion
string fn(string s)
{
    string r = "";
    for (char ch : s)
        r += (ch == '0' ? '1' : '0');
    reverse(r.begin(), r.end());
    return r;
}
string findKthBitUtil(int n)
{
    if (n == 1)
        return "0";

    string k = findKthBitUtil(n - 1);

    return k + "1" + fn(k);
}
char findKthBit(int n, int k)
{
    return findKthBitUtil(n)[k - 1];
}

// DP
string fn(string s)
{
    string r = "";
    for (char ch : s)
        r += (ch == '0' ? '1' : '0');
    reverse(r.begin(), r.end());
    return r;
}
string findKthBitUtil(int n, unordered_map<int, string> &m)
{
    if (n == 1)
        return "0";
    if (m.find(n) != m.end())
        return m[n];

    string k = findKthBitUtil(n - 1, m);

    return m[n] = (k + "1" + fn(k));
}
char findKthBit(int n, int k)
{
    unordered_map<int, string> m;
    return findKthBitUtil(n, m)[k - 1];
}

// TODO
// Binary Search