#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    ll res = 1;

    for (int i = 0; i < n && A[i] <= res; i++)
        res += A[i];

    cout << res << endl;
    return 0;
}