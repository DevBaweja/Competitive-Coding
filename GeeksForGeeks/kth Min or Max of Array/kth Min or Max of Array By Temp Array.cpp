#include <iostream>
using namespace std;

int getMin(int temp[], int k)
{
    int min = 0;
    for (int i = 1; i < k; i++)
        if (temp[i] < temp[min])
            min = i;
    return min;
}

int kthSmallestByTempArray(int A[], int n, int k)
{
    int temp[k];
    for (int i = 0; i < k; i++)
        temp[i] = A[i];

    int min = getMin(temp, k);

    for (int i = k; i < n; i++)
    {
        if (A[i] > A[min])
        {
            A[min] = A[i];
            min = getMin(temp, k);
        }
    }
    return temp[k];
}
// Time-
// Space- O(k)
// k
int main()
{
    int A[] = {12, 3, 5, 7, 19};
    int n = 5, k = 2;
    cout << kthSmallestByTempArray(A, n, k);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}