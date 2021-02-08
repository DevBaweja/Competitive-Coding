#include <iostream>
using namespace std;

// h-sort

void shellSort(int A[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++)
            for (int j = i; j >= gap && A[j] < A[j - gap]; j -= gap)
                swap(A[j], A[j - gap]);
}
// Time- O(n^2)

int main()
{
    int A[] = {12, 34, 54, 2, 3};
    int n = 5;

    shellSort(A, n);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}