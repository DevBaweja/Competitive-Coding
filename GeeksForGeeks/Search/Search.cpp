#include <iostream>
using namespace std;

int binarySearch(int A[], int low, int high, int k)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (A[mid] == k)
        return mid;

    if (k < A[mid])
        return binarySearch(A, low, mid - 1, k);
    return binarySearch(A, mid + 1, high, k);
}
// Time- O(log(n))

int main()
{
    int A[] = {2, 3, 4, 10, 40};
    int n = 5;
    int k = 10;
    cout << binarySearch(A, 0, n - 1, k);
    return 0;
}