#include <bits/stdc++.h>
using namespace std;

int setBits(int n)
{
    int res = 0;
    while (n)
    {
        res += n & 1;
        n = n >> 1;
    }
    return res;
}

int setBits(int n)
{
    int res = 0;
    while (n)
    {
        int rsb = n & -n;
        n -= rsb;
        res++;
    }
    return res;
}