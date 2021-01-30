#include <iostream>
#include <algorithm>
using namespace std;

int getMinDiff(int A[], int n, int k)
{
    sort(A, A + n);
    int minDiff = A[n - 1] - A[0];
    int small = A[0] + k;
    int big = A[n - 1] - k;

    if (small > big)
        swap(small, big);

    for (int i = 1; i < n - 1; i++)
    {
        int substract = A[i] - k;
        int add = A[i] + k;

        if (substract >= small || add <= big)
            continue;

        // Greedy
        if (big - substract <= add - small)
            small = substract;
        else
            big = add;
    }
    return min(minDiff, big - small);
}
// Time- O(n*log(n))
// Sorting

int main()
{
    int A[] = {1, 5, 15, 10};
    int n = 4;
    int k = 3;
    cout << getMinDiff(A, n, k);

    return 0;
}
