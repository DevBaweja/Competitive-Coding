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

    ll median = A[n / 2];
    ll result = 0;
    for (int i = 0; i < n; i++)
        result += abs(A[i] - median);
    cout << result << endl;
    return 0;
}