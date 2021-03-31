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

    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i];

    ll result = INT_MAX;
    for (int i = 0; i < (1 << n); i++)
    {
        ll subset = 0;
        for (int j = 0; j < n; j++)
        {
            if (1 << j & i)
                subset += A[j];
        }
        result = min(result, abs(sum - 2 * subset));
    }
    cout << result << endl;
    return 0;
}