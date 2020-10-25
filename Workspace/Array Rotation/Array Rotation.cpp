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

void leftShift(int A[], int n)
{
    int temp = A[0];
    for (int i = 1; i < n; i++)
        A[i - 1] = A[i];
    A[n - 1] = temp;
}
void rotateByTemp(int A[], int d, int n)
{
    int temp;
    for (int i = 0; i < d; i++)
        leftShift(A, n);
}
// Time O(n*d)
// Space O(1)

int gcd(int a, int b)
{
    // base case
    if (a == b)
        return a;

    if (a > b)
        return gcd(a - b, b);
    if (a < b)
        return gcd(a, b - a);
}
void rotateBySet(int A[], int d, int n)
{
    int no = gcd(n, d);
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int d = 3;
    int n = 12;

    rotateBySet(A, d, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}