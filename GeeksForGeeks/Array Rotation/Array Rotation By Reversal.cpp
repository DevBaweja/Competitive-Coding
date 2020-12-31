#include <iostream>

using namespace std;

void reverse(int A[], int si, int fi)
{
    while (si < fi)
    {
        int temp = A[si];
        A[si] = A[fi];
        A[fi] = temp;
        si++;
        fi--;
    }
}

void rotateByReversal(int A[], int d, int n)
{
    reverse(A, 0, d - 1);
    reverse(A, d, n - 1);
    reverse(A, 0, n - 1);
}
// Time O(n)
// Space O(1)

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
    int n = 7;

    rotateByReversal(A, d, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}
