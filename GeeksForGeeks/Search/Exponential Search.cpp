#include <iostream>
using namespace std;

int binarySearch(int A[], int left, int right, int k)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (k < A[mid])
        return binarySearch(A, left, mid - 1, k);
    return binarySearch(A, mid + 1, right, k);
}

int exponentialSearch(int A[], int n, int k)
{
    if (A[0] == k)
        return 0;
    int i = 1;
    while (i < n && A[i] < k)
        i *= 2;
    return binarySearch(A, i / 2, min(i, n), k);
}
// Time- O(log(n))
// Useful for unbounded search, where size of array is infinite
// Works better than binary search for bounded array.

int main()
{
    int A[] = {2, 3, 4, 10, 40};
    int n = 5;
    int k = 10;
    cout << exponentialSearch(A, n, k);
    return 0;
}