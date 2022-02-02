#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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