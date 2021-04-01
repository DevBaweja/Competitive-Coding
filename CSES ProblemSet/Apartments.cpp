#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int A[n], B[m];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];

    sort(A, A + n);
    sort(B, B + m);

    int res = 0;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (B[j] >= (A[i] - k) && B[j] <= (A[i] + k))
        {
            i++;
            j++;
            res++;
        }
        else if (B[j] <= (A[i] - k))
            j++;
        else if (B[j] >= (A[i] + k))
            i++;
    }
    cout << res << endl;
    return 0;
}
