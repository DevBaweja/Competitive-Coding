#include <bits/stdc++.h>
using namespace std;

int fun(string &s)
{
    long long int ac = 0, bc = 0, cc = 0;
    int mod = 1e9 + 7;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            ac = 2 * ac + 1;
        else if (s[i] == 'b')
            bc = 2 * bc + ac;
        else if (s[i] == 'c')
            cc = 2 * cc + bc;
        ac %= mod;
        bc %= mod;
        cc %= mod;
    }
    return cc;
}