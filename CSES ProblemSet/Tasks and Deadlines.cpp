#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i].first >> A[i].second;

    sort(A.begin(), A.end());
    ll res = 0, time = 0;
    for (int i = 0; i < n; i++)
    {
        time += A[i].first;
        res += A[i].second - time;
    }
    cout << res << endl;
    return 0;
}