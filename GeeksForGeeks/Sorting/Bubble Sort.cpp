#include <iostream>
using namespace std;

void bubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool is_swap = false;
        // As i element is already sorted
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                is_swap = true;
                swap(A[j], A[j + 1]);
            }
        }
        if (!is_swap)
            break;
    }
}
// Worst/Average Time- O(n*n)
// Best Time- O(n)
// Space- O(1)
// In Place- Yes
// Stable- Yes

void bubbleSortRecursive(int A[], int n)
{
    if (n == 1)
        return;
    int is_swap = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            swap(A[i], A[i + 1]);
            is_swap = true;
        }
    }
    if (is_swap)
        bubbleSortRecursive(A, n - 1);
}

int main()
{
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    // bubbleSort(A, n);
    bubbleSortRecursive(A, n);

    for (int i = 0; i < n; i++)
        cout
            << A[i] << " ";
    return 0;
}