#include <iostream>
using namespace std;

void merge(int A[], int B[], int n, int m, int C[])
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i < n)
        C[k++] = A[i++];
    while (j < m)
        C[k++] = B[j++];
}
// Time- O(n+m)
// Space- O(n+m)

void mergeInsertion(int A[], int B[], int n, int m)
{
    for (int i = m - 1; i >= 0; i--)
    {
        int last = A[n - 1];
        int j;
        // Shifting
        for (j = n - 2; j >= 0 && A[j] > B[i]; j--)
            A[j + 1] = A[j];
        if (j != n - 2 || last > B[i])
        {
            A[j + 1] = B[i];
            B[i] = last;
        }
    }
}
// Time- O(n*m)
// Space- O(1)

int main()
{
    int A[] = {1, 3, 5, 7};
    int n = 4;

    int B[] = {2, 4, 6, 8};
    int m = 4;

    /*
    int C[n + m];
    merge(A, B, n, m, C);
    for (int i = 0; i < n + m; i++)
        cout << C[i] << " ";
    */

    mergeInsertion(A, B, n, m);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    for (int j = 0; j < m; j++)
        cout << B[j] << " ";

    return 0;
}