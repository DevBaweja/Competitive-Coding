#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n;
    ll sum = 0;
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        ll temp;
        cin >> temp;
        sum += temp;
    }
    cout << n * (n + 1) / 2 - sum;
}