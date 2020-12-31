#include <iostream>

using namespace std;

void swap(int A[], int si, int fi, int d)
{
    for (int i = 0; i < d; i++)
    {
        int temp = A[si + i];
        A[si + i] = A[fi + i];
        A[fi + i] = temp;
    }
}

void rotateByBlockSwap(int A[], int d, int n)
{
    if (d == n - d)
    {
        // Same size
        swap(A, 0, n - d, d);
    }
    if (d < n - d)
    // A is shorter than B
    {
        swap(A, 0, n - d, d);
        rotateByBlockSwap(A, d, n - d);
    }
    if (d > n - d)
    // B is shorter than A
    {
        swap(A, 0, d, n - d);
        rotateByBlockSwap(A + n - d, 2 * d - n, d);
    }
}
// Time O(n)
// Space O(1)

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
    int n = 7;

    rotateByBlockSwap(A, d, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}
