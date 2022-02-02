#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int x = 0;
    for (int el : nums)
        x ^= el;
    return x;
}