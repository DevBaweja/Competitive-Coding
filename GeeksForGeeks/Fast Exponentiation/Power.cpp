#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return x;

    int temp = power(x, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    else
        return temp * x * temp;
}

int powerMod(int x, int n, int mod)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    int temp = power(x, n / 2) % mod;
    if (n % 2 == 0)
        return (temp * temp) % mod;
    else
        return (temp * x * temp) % mod;
}

int main()
{
    int x = 5, n = 4;
    int mod = 109;
    cout << power(x, n) << endl;
    cout << powerMod(x, n, mod) << endl;
}