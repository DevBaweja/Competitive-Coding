#include <iostream>

using namespace std;

void leftShift(int A[], int n)
{
    int temp = A[0];
    for (int i = 1; i < n; i++)
        A[i - 1] = A[i];
    A[n - 1] = temp;
}
void rotateByShifting(int A[], int d, int n)
{
    int temp;
    for (int i = 0; i < d; i++)
        leftShift(A, n);
}
// Time O(n*d)
// Space O(1)

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
    int n = 7;

    rotateByShifting(A, d, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}
