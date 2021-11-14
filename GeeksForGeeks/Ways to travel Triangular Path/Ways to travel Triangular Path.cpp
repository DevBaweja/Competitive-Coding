#include <bits/stdc++.h>
using namespace std;

// DP
int countWay(int n)
{
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    vector<int> c(n + 1, 0);
    a[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        a[i] = b[i - 1] + c[i - 1];
        b[i] = a[i - 1] + c[i - 1];
        c[i] = a[i - 1] + b[i - 1];
    }

    return a[n];
}

// DP Space Optimized
int countWay(int n)
{
    int pa = 1, pb = 0, pc = 0;
    int na = 0, nb = 0, nc = 0;

    for (int i = 0; i < n; i++)
    {
        na = pb + pc;
        nb = pa + pc;
        nc = pa + pb;
        pa = na;
        pb = nb;
        pc = nc;
    }

    return pa;
}