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

int findPivot(int A[], int low, int high)
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
        return findPivot(A, low, mid - 1);
    // Right
    if (A[low] < A[mid])
        return findPivot(A, mid + 1, high);
}

int pivotedBinarySearch(int A[], int n, int el)
{
    int pivot = findPivot(A, 0, n - 1);

    if (pivot == -1)
        return binarySearch(A, 0, n - 1, el);
    if (A[pivot] == el)
        return pivot;

    // Left
    if (A[0] <= el)
        return binarySearch(A, 0, pivot - 1, el);
    // Right
    if (A[0] > el)
        return binarySearch(A, pivot + 1, n - 1, el);
}

int main()
{
    int A[] = {30, 40, 50, 10, 20};
    int n = 5;
    int el = 10;
    cout << pivotedBinarySearch(A, n, el);
}