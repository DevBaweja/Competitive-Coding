#include <iostream>
using namespace std;

int left(int i)
{
    return 2 * i + 1;
}
int right(int i)
{
    return 2 * (i + 1);
}

void heapify(int A[], int n, int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);
    // Top Down

    if (l < n && A[l] > A[smallest])
        smallest = l;
    if (r < n && A[r] > A[smallest])
        smallest = r;

    if (i != smallest)
    {
        swap(A[i], A[smallest]);
        heapify(A, n, smallest);
    }
}
// Heapify single node O(log(n))
// No leaf node need heapify
// Last non leaf = Parent of last leaf (n-1) = ((n-1)-1)/2 = (n/2)-1

void heapSort(int A[], int n)
{
    int start = (n / 2) - 1;
    for (int i = start; i >= 0; i--)
        heapify(A, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}
// Time- O(n*log(n))
// O(n) to create and build heap
// O(log(n)) for heapify
// In Place- Yes
// Stable- No
int main()
{
    int A[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17, 2};
    int n = 12;

    heapSort(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}