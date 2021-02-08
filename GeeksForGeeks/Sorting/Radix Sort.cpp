#include <iostream>
#include <vector>
using namespace std;

int maximum(int A[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, A[i]);
    return maxi;
}

void countSort(int A[], int n, int exp)
{
    int base = 10;
    int count[base] = {0};
    // Count
    for (int i = 0; i < n; i++)
        count[(A[i] / exp) % base]++;
    // Index
    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];

    int B[n];
    // Reverse iterate to make sorting stable
    for (int i = n - 1; i >= 0; i--)
        B[--count[(A[i] / exp) % base]] = A[i];

    for (int i = 0; i < n; i++)
        A[i] = B[i];
}

void radixSort(int A[], int n)
{
    int maxi = maximum(A, n);
    for (int exp = 1; maxi / exp > 0; exp *= 10)
        countSort(A, n, exp);
}
// Element range from 1 to n^2
// Counting Sort O(n+k) = O(n+n^2) = O(n^2)
// Time- O(d*(n+b))
// b - base
// d - max digit
// k - max number
// d = logb(k)
// O(logb(k)*(n+b))

// Let k <= n^c
// O(logb(n)*n)
// b = n
// O(n)

// Range 1 to n^c and base n (every digit takes log2(n) bits) - O(n)

// 9 items and 5 digit octal number
// O(n*d*b)

int main()
{
    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;
    radixSort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}