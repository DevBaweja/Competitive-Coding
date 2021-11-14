#include <bits/stdc++.h>
using namespace std;

bool isValid(int n)
{
    unordered_map<int, int> m;
    while (n)
    {
        m[n % 10]++;
        n /= 10;
    }
    for (pair<int, int> p : m)
        if (p.first != p.second)
            return false;
    return true;
}

int nextBeautifulNumber(int n)
{
    while (true)
    {
        n++;
        if (isValid(n))
            return n;
    }
    return -1;
}

bool isValid(int n)
{
    int size = 10;
    vector<int> m(size, 0);
    while (n)
    {
        m[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < size; i++)
        if (m[i] && m[i] != i)
            return false;
    return true;
}

int nextBeautifulNumber(int n)
{
    while (true)
    {
        n++;
        if (isValid(n))
            return n;
    }
    return -1;
}
