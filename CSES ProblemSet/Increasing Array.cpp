#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    ll maximum = 0, result = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        maximum = max(maximum, x);
        result += maximum - x;
    }
    cout << result;
}