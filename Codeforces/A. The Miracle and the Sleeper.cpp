#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        if ((r / 2 + 1) >= l)
            cout << (r % (r / 2 + 1));
        else
            cout << r % l;
    }
    return 0;
}