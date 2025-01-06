#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Recursion
// Time - O(log(n))
double myPowUtil(double x, ll n)
{
    if (!n)
        return 1.0;

    double temp = myPowUtil(x, n / 2);
    if (n & 1ll)
        return temp * x * temp;
    return temp * temp;
}
double myPow(double x, ll n)
{
    if (n == 0ll)
        return 1.0;
    if (n < 0ll)
        return myPowUtil(1.0 / x, -n);
    return myPowUtil(x, n);
}

// Recursion
double myPow(double x, ll n) {
    if(n == 0)
        return 1;
    if(n < 0) {
        x = 1/x;
        n = -n;
    }
    double half = myPow(x, n/2);
    if(n&1)
        return x*half*half;
    return half*half;
}