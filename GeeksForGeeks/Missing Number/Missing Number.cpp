#include <iostream>
using namespace std;

int missingNumberNaive(int A[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i];
    return (n + 1) * (n + 2) / 2 - sum;
}
// Time - O(n)
// Space - O(1)

// Avoid Overflow
int missingNumberOverflow(int A[], int n)
{
    int sum = 1;
    for (int i = 0; i < n; i++)
        sum += (i + 2) - A[i];
    return sum;
}
// Time - O(n)
// Space - O(1)

// a = a1 ^ a2 ... an
// b = a1 ^ a2 ... an-1
// a^b = an

int missingNumberXOR(int A[], int n)
{
    int x1 = A[0];
    for (int i = 1; i < n; i++)
        x1 ^= A[i];
    int x2 = 1;
    for (int i = 2; i <= n + 1; i++)
        x2 ^= i;
    return x1 ^ x2;
}
// Time - O(n)
// Space - O(1)

int main()
{
    int A[] = {1, 2, 4, 6, 3, 7, 8};
    int n = 7;
    int B[] = {1, 2, 3, 5};
    int m = 4;
    cout << missingNumberXOR(A, n) << " " << missingNumberXOR(B, m);
    return 0;
}