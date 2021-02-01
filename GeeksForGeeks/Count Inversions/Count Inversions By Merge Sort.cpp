#include <iostream>
using namespace std;

int merge(int A[], int left, int mid, int right)
{
    int count = 0;
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
        {
            A[k++] = R[j++];
            count += mid - i;
        }
    }

    while (i < n)
        A[k++] = L[i++];
    while (j < m)
        A[k++] = R[j++];

    return count;
}

void mergeSort(int A[], int left, int right, int *count)
{
    if (left >= right)
        return;
    int mid = (left + right - 1) / 2;
    mergeSort(A, left, mid, count);
    mergeSort(A, mid + 1, right, count);
    *count += merge(A, left, mid, right);
}

int invCountMerge(int A[], int n)
{
    int count = 0;
    mergeSort(A, 0, n - 1, &count);
    return count;
}
// Space- O(n)
// Time- O(n*log(n))

int main()
{
    int A[] = {1, 20, 6, 4, 5};
    int n = 5;
    cout << invCountMerge(A, n);
    return 0;
}