#include <bits/stdc++.h>
using namespace std;

int power(int n)
{
    int rsb = 0;
    while (n)
    {
        rsb = n & -n;
        n -= rsb;
    }
    return rsb;
}
int main()
{
    int n;
    cin >> n;
    int p = power(n);
    int l = n - p;
    cout << (2 * l + 1);
}