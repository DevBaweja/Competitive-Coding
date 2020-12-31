#include <iostream>

using namespace std;
// Sorted Array
int binarySearchRecursive(int A[], int l, int r, int el)
{
    if (r >= l)
    {

        int mid = (l + r) / 2;
        if (A[mid] == el)
            return mid;
        if (el < A[mid])
            return binarySearchRecursive(A, l, mid - 1, el);
        if (el > A[mid])
            return binarySearchRecursive(A, mid + 1, r, el);
    }
    return -1;
}
// Time O(log(n)) ie T(n) = T(n/2)
// Space O(log(n)) ie Recursive Stack

int binarySearchIterative(int A[], int l, int r, int el)
{
    while (r >= l)
    {
        int mid = (l + r) / 2;
        if (A[mid] == el)
            return mid;
        if (el < A[mid])
            r = mid - 1;
        if (el > A[mid])
            l = mid + 1;
    }
    return -1;
}
// Time O(log(n))
// Space O(1)

int main()
{
    int A[] = {2, 3, 4, 10, 40};
    int n = 5;
    int el = 10;
    cout << binarySearchRecursive(A, 0, n - 1, el);
}