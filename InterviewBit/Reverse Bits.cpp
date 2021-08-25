#include <bits/stdc++.h>
using namespace std;

unsigned int reverse(unsigned int A)
{
    unsigned int B = 0;
    int size = 32;
    while (size--)
    {
        B <<= 1;
        B = B | A & 1;
        A >>= 1;
    }
    return B;
}
