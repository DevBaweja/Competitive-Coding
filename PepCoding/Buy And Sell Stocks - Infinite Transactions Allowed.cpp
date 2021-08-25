#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int buy = 0, sell = 0;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] >= A[sell])
            sell++;
        else
        {
            res += A[sell] - A[buy];
            buy = i;
            sell = i;
        }
    }
    res += A[sell] - A[buy];
    cout << res;
    return 0;
}