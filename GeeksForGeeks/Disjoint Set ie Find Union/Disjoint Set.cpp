#include <bits/stdc++.h>
using namespace std;

int find(int a[], int x)
{
    if (a[x] == x)
        return x;
    return find(a, a[x]);
}
void unionSet(int a[], int x, int z)
{
    int xp = find(a, x);
    int zp = find(a, z);
    if (xp == zp)
        return;
    a[xp] = zp;
}
