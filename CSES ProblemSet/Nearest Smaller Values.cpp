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

    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        while (j >= 0 && A[j] >= A[i])
            j--;
        cout << j + 1 << " ";
    }
    return 0;
}
*/

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> N(n);
    for (int i = 0; i < n; i++)
    {
        N[i] = i - 1;
        while (~N[i] && A[N[i]] >= A[i])
            N[i] = N[N[i]];
        cout << N[i] + 1 << " ";
    }
}
