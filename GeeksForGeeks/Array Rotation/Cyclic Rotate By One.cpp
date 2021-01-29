#include <iostream>
using namespace std;

void rotate(int A[], int n)
{
    int temp = A[0];
    for (int i = 1; i < n; i++)
        swap(A[i - 1], A[i]);
    A[n - 1] = temp;
}
// Time- O(n)

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;

    rotate(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}