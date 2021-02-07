#include <iostream>
#include <algorithm>
using namespace std;

int kthSmallest(int A[], int n, int k)
{
    sort(A, A + n);
    return A[k - 1];
}
// Time O(nlog(n))

int kthSmallestByBubble(int A[], int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
        }
    }
    return A[k - 1];
}
// Time- O(nk)

int main()
{
    int A[] = {12, 3, 5, 7, 19};
    int n = 5, k = 2;
    // cout << kthSmallest(A, n, k);
    cout << kthSmallestByBubble(A, n, k);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}