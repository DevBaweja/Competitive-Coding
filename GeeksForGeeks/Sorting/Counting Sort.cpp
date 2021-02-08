#include <iostream>
using namespace std;

int maximum(int A[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, A[i]);
    return maxi + 1;
}

void countSort(int A[], int n)
{
    int maxi = maximum(A, n);
    int count[maxi];
    // Init
    for (int i = 0; i < maxi; i++)
        count[i] = 0;
    // Count
    for (int i = 0; i < n; i++)
        count[A[i]]++;
    // Index
    for (int i = 1; i < maxi; i++)
        count[i] += count[i - 1];

    int B[n];
    // Reverse iterate to make sorting stable
    for (int i = n - 1; i >= 0; i--)
        B[--count[A[i]]] = A[i];

    for (int i = 0; i < n; i++)
        A[i] = B[i];
}
// Time- O(n+k)
// k - Range of input
// Space- O(n+k)

int main()
{
    int A[] = {1, 4, 1, 2, 7, 5, 2};
    int n = 7;
    countSort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}