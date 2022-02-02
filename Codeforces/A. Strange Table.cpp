#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll k;
        cin >> k;

        ll col = ceil(1.0 * k / n);
        ll row = k - (col - 1) * n;
        cout << (row - 1) * m + col << "\n";
    }
    return 0;
}