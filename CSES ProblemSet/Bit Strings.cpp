#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n, s = 1;
    cin >> n;
    for (ll i = 0; i < n; i++)
        s = (2 * s) % ((int)1e9 + 7);
    cout << s << "\n";
    return 0;
}