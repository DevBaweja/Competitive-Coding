#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        int d0, d1;
        cin >> d0 >> d1;
        int s = d0 + d1;

        int c = ((2 * s) % 10) + ((4 * s) % 10) + ((8 * s) % 10) + ((6 * s) % 10);

        ll num_cycles = (k - 3) / 4;
        ll total = 0;

        if (k == 2)
            total = s;
        else
        {
            total = s + (s % 10) + (c * 1ll * num_cycles);
            int left_over = (k - 3) - (4 * num_cycles);
            int temp = 2;
            for (int i = 1; i <= left_over; i++)
            {
                total += (temp * s) % 10;
                temp = (2 * temp) % 10;
            }
        }
        if ((total % 3) == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}