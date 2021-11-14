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

int main()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll res = 0;
    ll cur = v[0];
    for (int i = 1; i < n; i++)
    {
        res += max(cur - v[i], 0ll);
        cur = max(cur, v[i]);
    }
    cout << res;
}