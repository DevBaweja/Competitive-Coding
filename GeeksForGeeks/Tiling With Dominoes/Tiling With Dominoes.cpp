#include <bits/stdc++.h>
using namespace std;

int tilingDominoes(int n)
{
    long long mod = 1e9 + 7;
    vector<long long> total(n + 1, 0);
    vector<long long> part(n + 1, 0);

    total[0] = 1;
    total[1] = 0;
    part[0] = 0;
    part[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        total[i] = (total[i - 2] + part[i - 1] + part[i - 1]) % mod;
        part[i] = (total[i - 1] + part[i - 2]) % mod;
    }
    return (int)total[n];
}
