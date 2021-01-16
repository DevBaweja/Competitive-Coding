#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll y, x;
        cin >> y >> x;
        ll z, result;
        z = max(x, y);
        if (z == x)
        {
            if (z % 2 != 0)
                result = z * z - y + 1;
            else
                result = (z - 1) * (z - 1) + 1 + y - 1;
        }
        if (z == y)
        {
            if (z % 2 == 0)
                result = z * z - x + 1;
            else
                result = (z - 1) * (z - 1) + 1 + x - 1;
        }
        cout << result << endl;
    }
}