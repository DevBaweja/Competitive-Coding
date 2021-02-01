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

int main()
{
    int A[] = {1, 3, 5, 7};
    int n = 4;

    int B[] = {2, 4, 6, 8};
    int m = 4;

    int C[n + m];

    merge(A, B, n, m, C);

    for (int i = 0; i < n + m; i++)
        cout << C[i] << " ";

    return 0;
}