#include <iostream>
#include <vector>
using namespace std;

void repeatingHashMap(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (A[abs(A[i])] < 0)
            cout << abs(A[i]) << " ";
        A[abs(A[i])] = -A[abs(A[i])];
    }
}
// Time- O(n)
// Space- O(1)
// It will modify array but reduce space as compared to count array
// Only account for 2 occurrence

void repeatingFrequency(int A[], int n)
{
    for (int i = 0; i < n; i++)
        A[A[i] % n] += n;

    for (int i = 0; i < n; i++)
        if ((A[i] / n) >= 2)
            cout << i << " ";
}
// Time- O(n)
// Space- O(1)
// Don't maintain order

void repeatingFrequencyModified(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // First Occurence
        if (A[A[i] % n] >= n && A[A[i] % n] < 2 * n)
        {
            cout << A[i] % n << " ";
        }
        A[A[i] % n] += n;
    }
}

int main()
{
    int A[] = {1, 2, 3, 6, 3, 6, 1};
    int n = 7;
    repeatingFrequencyModified(A, n);
}
