#include <bits/stdc++.h>
using namespace std;

int divide(int a, int b)
{
    while (a % b == 0)
        a /= b;
    return a;
}
bool isUgly(int n)
{
    if (n <= 0)
        return false;
    return divide(divide(divide(n, 2), 3), 5) == 1;
}