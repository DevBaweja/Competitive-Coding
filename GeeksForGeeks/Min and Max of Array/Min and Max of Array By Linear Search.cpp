#include <iostream>
using namespace std;
struct Pair
{
    int min, max;
};

// Linear Search
struct Pair getMinMax(int A[], int n)
{
    struct Pair minmax;
    if (n == 1)
    {
        int el = A[0];
        minmax.min = el;
        minmax.max = el;
    }

    // Initialize min and max
    if (A[0] < A[1])
    {
        minmax.min = A[0];
        minmax.max = A[1];
    }
    else
    {
        minmax.min = A[1];
        minmax.max = A[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (A[i] < minmax.min)
        {
            minmax.min = A[i];
        }
        else if (A[i] > minmax.max)
        {
            minmax.max = A[i];
        }
    }
    return minmax;
}
// Time O(n)

// Best Case - Increasing Order
// 1 + (n-2) = n-1

// Worst Case - Decreasing Order
// Comparison 1 + 2*(n-2) = 2n-3

int main()
{
    int A[] = {1000, 11, 445, 1, 330, 3000};
    int n = 6;
    struct Pair minmax = getMinMax(A, n);

    cout << minmax.min << " " << minmax.max << endl;
    return 0;
}
