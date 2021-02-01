#include <iostream>
using namespace std;

int invCountNaive(int A[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i] > A[j])
                count++;
    return count;
}
// Time- O(n*n)
// Space- O(1)

int main()
{
    int A[] = {1, 20, 6, 4, 5};
    int n = 5;
    cout << invCountNaive(A, n);
    return 0;
}