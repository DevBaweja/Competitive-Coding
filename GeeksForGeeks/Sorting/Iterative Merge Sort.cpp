
#include <iostream>
using namespace std;

void merge(int A[], int left, int mid, int right)
{
    int n = mid - left + 1;
    int m = right - mid;

    int L[n], R[m];
    for (int i = 0; i < n; i++)
        L[i] = A[left + i];
    for (int i = 0; i < m; i++)
        R[i] = A[mid + i + 1];

    int i = 0, j = 0;
    int k = left;

    while (i < n && j < m)
    {
        if (L[i] < R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n)
        A[k++] = L[i++];
    while (j < m)
        A[k++] = R[j++];
}

void mergeSort(int A[], int n)
{
    for (int size = 1; size < n; size = 2 * size)
    {
        for (int left = 0; left < n - 1; left += 2 * size)
        {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);
            merge(A, left, mid, right);
        }
    }
}

int main()
{
    int A[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    mergeSort(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
