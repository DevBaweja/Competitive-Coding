#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, r, m;
        cin >> x >> r >> m;
        r *= 60;
        m *= 60;
        if (r <= x)
            cout << "YES\n";
        else
        {
            ll value = x + 2 * (r - x);
            if (value <= m)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}