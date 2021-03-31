#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (2 * a >= b && 2 * b >= a && (a + b) % 3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}