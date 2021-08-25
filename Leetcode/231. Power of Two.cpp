#include <bits/stdc++.h>
using namespace std;

// Count Set Bits
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    int c = 0;
    while (n)
    {
        c += n & 1;
        n = n >> 1;
    }
    return c == 1;
}