#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    // 2x3 or 3x2 and there are 2 ways
    // (n-1)(n-2) such rectangles
    // Total ways = n2(n2-1)/2
    ll n;
    cin >> n;
    for (ll k = 1; k <= n; k++)
    {
        ll total = (k * k * (k * k - 1)) / 2;
        if (k > 2)
            total -= 2 * 2 * (k - 1) * (k - 2);
        cout << total << endl;
    }
}
