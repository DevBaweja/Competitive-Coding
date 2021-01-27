#include <iostream>
using namespace std;
struct Pair
{
    int min, max;
};

// Compare in Pairs
struct Pair getMinMaxCompare(int A[], int n)
{
    struct Pair minmax;
    int i;
    if (n % 2 == 0)
    {
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
        i = 2;
    }
    else
    {
        int el = A[0];
        minmax.min = el;
        minmax.max = el;
        i = 1;
    }

    while (i < n - 1)
    {
        if (A[i] > A[i + 1])
        {
            if (A[i] > minmax.max)
                minmax.max = A[i];
            if (A[i + 1] < minmax.min)
                minmax.min = A[i + 1];
        }
        else
        {
            if (A[i + 1] > minmax.max)
                minmax.max = A[i + 1];
            if (A[i] < minmax.min)
                minmax.min = A[i];
        }
        i += 2;
    }

    return minmax;
}
// Time O(n)

// If n is odd
// 3 * (n-1)/2

// If n is even
// 1 + 3 * (n-2)/2 = 3*(n/2) - 2

int main()
{
    int A[] = {1000, 11, 445, 1, 330, 3000};
    int n = 6;
    struct Pair minmax = getMinMaxCompare(A, n);

    cout << minmax.min << " " << minmax.max << endl;
    return 0;
}
