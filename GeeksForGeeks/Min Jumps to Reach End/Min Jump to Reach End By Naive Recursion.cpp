#include <iostream>
using namespace std;

int minJumps(int A[], int n)
{
    if (n == 1)
        return 0;
    int jumps = INT_MAX;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + A[i] >= n - 1)
        {
            int sub_jumps = minJumps(A, i + 1);
            if (sub_jumps != INT_MAX)
                jumps = min(jumps, sub_jumps + 1);
        }
    }
    return jumps;
}

// Time- O(n*n)
// Space- O(1)

int main()
{
    int A[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = 10;
    cout << minJumps(A, n);
    return 0;
}