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
// Space- O(n)
// Time- O(n*log(n))
// T(n) =2*T(n/2)+O(n)
// O(n) to merge
// In place- No
// Stable- Yes

void mergeSort(int A[], int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right - 1) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
}

int main()
{
    int A[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    mergeSort(A, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}