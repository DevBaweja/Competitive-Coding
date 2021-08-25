#include <bits/stdc++.h>
using namespace std;

int findComplement(int num)
{

    vector<int> v;
    while (num)
    {
        v.push_back(num & 1);
        num >>= 1;
    }
    reverse(v.begin(), v.end());
    int res = 0;
    for (int el : v)
    {
        res <<= 1;
        res |= !el;
    }
    return res;
}