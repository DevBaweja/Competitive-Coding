#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    // 1 2 3 4
    // 2 4 1 3
    // 1 2 3 4 5
    // 2 4 1 3 5
    for (ll i = 2; i <= n; i += 2)
        cout << i << " ";
    for (ll i = 1; i <= n; i += 2)
        cout << i << " ";
}