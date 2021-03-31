#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll result = 0;
    for (ll i = 5; i <= n; i *= 5)
        result += n / i;
    cout << result << "\n";
    return 0;
}