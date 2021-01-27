#include <iostream>
using namespace std;
struct Pair
{
    int min, max;
};

// Tournament Method
struct Pair getMinMaxRecursive(int A[], int low, int high)
{
    struct Pair minmax, mml, mmr;
    // One Element
    if (low == high)
    {
        minmax.min = A[low];
        minmax.max = A[high];
        return minmax;
    }

    // Two Element
    if (low == high - 1)
    {
        if (A[low] < A[high])
        {
            minmax.min = A[low];
            minmax.max = A[high];
        }
        else
        {
            minmax.min = A[high];
            minmax.max = A[low];
        }
        return minmax;
    }

    int mid = (low + high) / 2;

    mml = getMinMaxRecursive(A, low, mid);
    mmr = getMinMaxRecursive(A, mid + 1, high);

    // Compare Both Left and Right - Min and Max
    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;

    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;

    return minmax;
}
// Time O(n)

// Let T(n) be # of comparisons
// T(n) =T(floor(n/2)) + T(ceil(n/2)) + 2

// If n is power of 2
// T(n) = 2 * T(n/2) + 2
// T(n) = 3 * (n/2) - 2

// If n is not power of 2
// More than 3 * (n/2) - 2

int main()
{
    int A[] = {1000, 11, 445, 1, 330, 3000};
    int n = 6;
    struct Pair minmax = getMinMaxRecursive(A, 0, n - 1);

    cout << minmax.min << " " << minmax.max << endl;
    return 0;
}
