#include <iostream>
using namespace std;

void selectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minimum])
                minimum = j;
        }
        if (i != minimum)
            swap(A[i], A[minimum]);
    }
}
// Worst/Average Time- O(n*n)
// Space- O(1)
// Max Swapping- O(n)
// In Place- Yes
// Stable- No

void selectionSortStable(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minimum])
                minimum = j;
        }

        int key = A[minimum];
        while (minimum > i)
        {
            A[minimum] = A[minimum - 1];
            minimum--;
        }
        A[i] = key;
    }
}
// Stable- Yes

int main()
{
    int A[] = {4, 5, 3, 2, 4, 1};
    int n = 6;

    selectionSortStable(A, n);

    for (int i = 0; i < n; i++)
        cout
            << A[i] << " ";
    return 0;
}