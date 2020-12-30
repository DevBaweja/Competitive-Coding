#include <iostream>

using namespace std;

void rotateByArray(int A[], int d, int n)
{
    int B[d];
    for (int i = 0; i < d; i++)
        B[i] = A[i];
    for (int i = d; i < n; i++)
        A[i - d] = A[i];
    for (int i = 0; i < d; i++)
        A[i + n - d] = B[i];
}
// Time O(n)
// Space O(d)

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
    int n = 7;

    rotateByArray(A, d, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}