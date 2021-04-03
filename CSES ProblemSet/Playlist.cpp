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

    map<ll, int> m;
    int i = 0, j = 0;
    int result = 0;
    while (i < n && j < n)
    {
        if (m[A[j]] < 1)
        {
            m[A[j]]++;
            j++;
        }
        else
            i++;
        result = max(j - i, result);
    }
    cout << result << endl;
    return 0;
}