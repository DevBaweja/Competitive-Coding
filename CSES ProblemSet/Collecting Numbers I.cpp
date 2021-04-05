#include <bits/stdc++.h>
using namespace std;

/*
int main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> B(n);

    for (int i = 0; i < n; i++)
        B[A[i] - 1] = i;
    int result = 1;
    for (int i = 1; i < n; i++)
        result += B[i - 1] > B[i];

    cout << result << endl;
    return 0;
}
*/

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> B(n);

    for (int i = 0; i < n; i++)
        B[A[i] - 1] = i;
    int result = 1;
    for (int i = 1; i < n; i++)
        result += B[i - 1] > B[i];

    while (m--)
    {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        if (A[p] > A[q])
            result--;
        if (A[p] < A[q])
            result++;
        swap(A[p], A[q]);
        cout << result << "\n";
    }
    return 0;
}