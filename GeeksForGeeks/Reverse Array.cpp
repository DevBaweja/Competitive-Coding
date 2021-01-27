#include <iostream>
using namespace std;

void reverseArray(int A[], int start, int end)
{
    while (start < end)
    {
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
        start++;
        end--;
    }
}
// Time O(n)
// Space O(1)

void reverseArrayRecursive(int A[], int start, int end)
{
    if (start > end)
        return;
    int temp = A[start];
    A[start] = A[end];
    A[end] = temp;
    reverseArrayRecursive(A, start + 1, end - 1);
}
// Time O(n)
// Space O(1)

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    // reverseArray(A, 0, n - 1);
    reverseArrayRecursive(A, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}