#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        ll k;
        cin >> k;
        int res;
        ll index = 0;
        ll num;
        do
        {
            num = 9 * pow(10, index + 1);
            index++;
        } while (k < num);

        ll low = pow(10, index - 1);
        ll high = pow(10, index) - 1;

        cout << low << " " << high << endl;
    }
    return 0;
}