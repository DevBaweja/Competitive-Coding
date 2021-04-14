#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    ll sum = 0, count = 0;
    map<ll, int> m;
    m[0]++;
    for (int i = 0; i < n; i++)
    {
        sum = (sum + A[i] % n + n) % n;
        count += m[sum];
        m[sum]++;
    }
    cout << count << endl;
    return 0;
}