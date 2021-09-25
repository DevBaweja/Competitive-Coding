#include <bits/stdc++.h>
using namespace std;

int maxProduct(const vector<int> &A)
{
    int n = A.size();
    int mini = 1, maxi = 1;
    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
            swap(mini, maxi);
        maxi = max(A[i], maxi * A[i]);
        mini = min(A[i], mini * A[i]);
        res = max(res, maxi);
    }
    return res;
}
