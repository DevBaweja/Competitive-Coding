#include <iostream>
using namespace std;

void insertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
// Worst/Average Time- O(n*n)
// Best Time- O(n)
// Incremental Approach
// Space- O(1)
// In Place- Yes
// Stable- Yes

int binarySearch(int A[], int low, int high, int key)
{
    if (low >= high)
        return (key > A[low]) ? low + 1 : low;

    int mid = (low + high) / 2;

    if (key == A[mid])
        return mid + 1;

    if (key < A[mid])
        return binarySearch(A, low, mid - 1, key);

    if (key > A[mid])
        return binarySearch(A, mid + 1, high, key);
}

void insertionSortBinary(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        int loc = binarySearch(A, 0, j, key);
        while (j >= loc)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
// Instead of inserting in O(i), binary search- O(log(i))
// Time- O(n*n)
// Space- O(1)

int main()
{
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    insertionSortBinary(A, n);

    for (int i = 0; i < n; i++)
        cout
            << A[i] << " ";
    return 0;
}