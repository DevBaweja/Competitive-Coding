#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
int main()
{

    int n;
    cin >> n;
    ll k;
    cin >> k;

    vector<ll> M(n);
    for (int i = 0; i < n; i++)
        cin >> M[i];

    ll time = 0;
    while (1)
    {
        ll items = 0;
        for (int i = 0; i < n; i++)
            items += (time / M[i]);
        if (items >= k)
            break;
        time++;
    }

    cout << time << endl;
}
*/

// Using Binary Search
int main()
{
    int n;
    cin >> n;
    ll k;
    cin >> k;

    vector<ll> M(n);
    for (int i = 0; i < n; i++)
        cin >> M[i];

    ll maxValue = M[0];
    for (int i = 1; i < n; i++)
        maxValue = max(maxValue, M[i]);

    // Binary Search
    ll low = 1, high = 1e18;
    // high = maxValue * k;

    while (low < high)
    {
        ll mid = (low + high) / 2;
        ll items = 0;
        for (int i = 0; i < n; i++)
            items += min((mid / M[i]), (ll)1e9);

        if (items >= k)
            high = mid;
        else
            low = mid + 1;
    }
    cout << low << endl;
}