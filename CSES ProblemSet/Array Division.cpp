#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    ll lb = *max_element(A.begin(), A.end());
    ll rb = 1e18;
    while (lb < rb)
    {
        ll mb = (lb + rb) / 2;
        int parts = 0;
        ll subsum = 0;
        for (int i = 0; i < n; i++)
        {
            if (subsum + A[i] > mb)
            {
                parts++;
                subsum = 0;
            }
            subsum += A[i];
        }
        parts++;
        if (parts > k)
            lb = mb + 1;
        else
            rb = mb;
    }
    cout << lb << endl;
    return 0;
}