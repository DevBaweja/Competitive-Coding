#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> A(n + 1);
    A[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i + 1];
        A[i + 1] += A[i];
    }

    set<pair<ll, int>> s;
    ll ans = -1e18;
    for (int i = a; i <= n; i++)
    {
        s.insert({A[i - a], i - a});
        ans = max(ans, A[i] - (*s.begin()).first);
        if (i >= b)
            s.erase({A[i - b], i - b});
    }
    cout << ans << endl;
}