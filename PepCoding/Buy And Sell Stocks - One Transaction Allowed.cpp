#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int lsf = INT_MAX;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        lsf = min(lsf, A[i - 1]);
        res = max(res, A[i] - lsf);
    }
    cout << res;
    return 0;
}