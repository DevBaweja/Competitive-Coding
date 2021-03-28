#include <iostream>
#include <vector>
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
        vector<ll> A(n);
        for (ll i = 0; i < n; i++)
            cin >> A[i];

        bool odd = false;
        bool even = false;
        for (ll i = 0; i < n; i++)
        {
            if (A[i] % 2 == 1)
                odd = !odd;
            if (A[i] / 2 == 1)
                even = true;
        }
        int result = -1;
        if (!odd)
            result = 0;
        else if (even)
            result = 1;
        cout << result << "\n";
    }
    return 0;
}