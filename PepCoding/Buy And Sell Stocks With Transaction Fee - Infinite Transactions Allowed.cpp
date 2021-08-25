#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int k;
    cin >> k;

    int ob = -A[0];
    int os = 0;
    for (int i = 1; i < n; i++)
    {
        int nb = max(ob, os - A[i]);
        int ns = max(os, ob + A[i] - k);
        ob = nb;
        os = ns;
    }
    cout << os;
}