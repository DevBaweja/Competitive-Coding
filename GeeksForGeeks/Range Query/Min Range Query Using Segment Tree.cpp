#include <bits/stdc++.h>
using namespace std;

void constructTree(vector<int> &A, vector<int> &B, int low, int high, int pos)
{
    if (low == high)
    {
        B[pos] = A[low];
        return;
    }
    int mid = (low + high) / 2;

    constructTree(A, B, low, mid, 2 * pos + 1);
    constructTree(A, B, mid + 1, high, 2 * pos + 2);

    B[pos] = min(B[2 * pos + 1], B[2 * pos + 2]);
}

int rangeQuery(vector<int> &B, int qlow, int qhigh, int low, int high, int pos)
{
    // total overlap
    if (qlow <= low && qhigh >= high)
        return B[pos];
    // no overlap
    if (qlow > high || qhigh < low)
        return INT_MAX;
    int mid = (low + high) / 2;

    return min(rangeQuery(B, qlow, qhigh, low, mid, 2 * pos + 1),
               rangeQuery(B, qlow, qhigh, mid + 1, high, 2 * pos + 2));
}

int main()
{
    int n = 4;
    vector<int> A{-1, 2, 4, 0};

    vector<int> B(2 * n - 1, INT_MAX);
    int low = 0, high = n - 1;
    int pos = 0;
    constructTree(A, B, low, high, pos);
    int qlow = 1, qhigh = n - 2;
    cout << rangeQuery(B, qlow, qhigh, low, high, pos);
}

// Time- O(n)
// Space- O(n)
// Query- O(log(n))