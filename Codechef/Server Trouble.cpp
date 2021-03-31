#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll d = ceil(1.0 * n / k);
        int rem = n % k;
        int x;
        if (rem == 0)
            x = k;
        else
            x = rem;
        cout << d << " " << x << "\n";
    }
    return 0;
}