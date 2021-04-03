#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll res = (5 * 4 + 6 * 4) * (n / 4);
        if (n % 4 == 0)
            res += 4 * 4;
        if (n % 4 == 1)
            res += 21 - 1 - (n / 4 ? 1 : 0) * 4;
        if (n % 4 == 2)
            res += 21 * 2 - 2 * 2 - 1 * 2 - (n / 4 ? 1 : 0) * 2 * 4;
        if (n % 4 == 3)
            res += 21 * 3 - 3 * 1 - 2 * 3 - 1 * 2 - (n / 4 ? 1 : 0) * 3 * 4;
        cout << res << "\n";
    }
    return 0;
}