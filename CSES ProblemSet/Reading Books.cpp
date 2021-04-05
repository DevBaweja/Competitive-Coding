#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<ll> T(n);
    for (int i = 0; i < n; i++)
        cin >> T[i];

    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += T[i];

    sort(T.begin(), T.end());
    ll res = max(sum, 2ll * T[n - 1]);
    cout << res << endl;
}