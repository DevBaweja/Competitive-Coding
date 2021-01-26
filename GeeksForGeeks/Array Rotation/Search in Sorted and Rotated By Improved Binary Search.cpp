#include <iostream>

using namespace std;
// Sorted and Rotated

int binarySearch(int A[], int low, int high, int el)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2;
    if (el == A[mid])
        return mid;

    // Left
    if (el < A[mid])
        return binarySearch(A, low, mid - 1, el);
    // Right
    if (el > A[mid])
        return binarySearch(A, mid + 1, high, el);
}

int improvedSearch(int A[], int low, int high, int el)
{
    if (high < low)
        return -1;
    if (low == high)
        return low;

    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (mid < high && A[mid] > A[mid + 1])
        return mid;

    if (mid > low && A[mid] < A[mid - 1])
        return mid - 1;

    // Left
    if (A[low] >= A[mid])
        return improvedSearch(A, low, mid - 1, el);
    // Right
    if (A[low] < A[mid])
        return improvedSearch(A, mid + 1, high, el);
}

// Time O(log(n))
// Space O(1)

int main()
{
    int A[] = {30, 40, 50, 10, 20};
    int n = 5;
    int el = 10;
    cout << improvedSearch(A, 0, n - 1, el);
}