#include <iostream>
using namespace std;

int partition(int A[], int low, int high)
{
    int pivot = A[high];
    // Last Element as pivot
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[high]);
    return i;
}

void quickSort(int A[], int low, int high)
{
    if (low >= high)
        return;

    int pi = partition(A, low, high);

    quickSort(A, low, pi - 1);
    quickSort(A, pi + 1, high);
}
// Time- T(n) = T(k) + T(n-k-1) + O(n)
// (k) elements + pivot + (n-k-1) elements
// O(n) for parition

// Worst Case- Smallest or Largest as pivot
// T(n) = T(0) + T(n-1) + O(n) = T(n-1) + O(n)
// O(n*n)

// Best Case- Middle as pivot
// T(n) = 2*T(n/2) + O(n)
// O(n*log(n))

// Average Case- Let parition puts O(n/9) and O(9*n/10)
// T(n) = T(n/9) + T(9*n/10) + O(n)
// O(n*log(n))

// In place- Yes
// Stable- No

int main()
{
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}