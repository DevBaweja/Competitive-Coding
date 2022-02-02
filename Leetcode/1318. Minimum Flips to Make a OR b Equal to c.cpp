#include <bits/stdc++.h>
using namespace std;

// Bit Manipulation
int countBits(int n)
{
    int temp = n;
    int count = 0;
    while (temp)
    {
        temp -= (temp & -temp);
        count++;
    }
    return count;
}

int minFlips(int a, int b, int c)
{
    int res = a | b;
    int diff = res ^ c;
    int one = diff & c;
    int two = diff - one;
    return countBits(one) + countBits(two & a) + countBits(two & b);
}