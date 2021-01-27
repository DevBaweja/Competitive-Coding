#include <iostream>
#include <algorithm>
using namespace std;

int kthSmallest(int A[], int n, int k)
{
    sort(A, A + n);
    return A[k - 1];
}
// Time O(nlog(n))

int main()
{
    int A[] = {12, 3, 5, 7, 19};
    int n = 5, k = 2;
    cout << kthSmallest(A, n, k);
    return 0;
}