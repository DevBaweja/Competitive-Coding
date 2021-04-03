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

    ll result = A[0], current = A[0];
    for (int i = 1; i < n; i++)
    {
        current = max(A[i], current + A[i]);
        result = max(result, current);
    }
    cout << result << endl;
    return 0;
}