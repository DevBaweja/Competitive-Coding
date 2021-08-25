#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int ob = -A[0], os = 0, oc = 0;
    for (int i = 1; i < n; i++)
    {
        int nb = max(ob, oc - A[i]);
        int ns = max(os, ob + A[i]);
        int nc = max(oc, os);
        ob = nb;
        os = ns;
        oc = nc;
    }
    cout << os;
}