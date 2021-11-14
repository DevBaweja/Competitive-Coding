#include <bits/stdc++.h>
using namespace std;

// Binary Represent
bool hasAlternatingBits(int n)
{
    int cur = n % 2;
    n /= 2;
    while (n)
    {
        if (cur == n % 2)
            return false;
        cur = n % 2;
        n /= 2;
    }
    return true;
}

// Bit Manipulation
bool hasAlternatingBits(int n)
{
    n = n ^ (n >> 1);
    return (n & n + 1) == 0;
}