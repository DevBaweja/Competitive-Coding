#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A, A + n);

    int res = 0;
    int i = 0, j = n - 1;

    while (i <= j)
    {
        if (A[i] + A[j] <= x)
            i++;
        j--;
        res++;
    }
    cout << res << endl;
    return 0;
}
