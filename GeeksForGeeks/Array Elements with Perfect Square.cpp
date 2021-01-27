#include <bits/stdc++.h>
using namespace std;

int countSquares(int A[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i] == A[j] * A[j])
                count++;

    return count;
}
// Time O(n2)
// Space O(1)

int countSquaresByMap(int A[], int n)
{
    int count = 0;
    unordered_map<int, int> M;
    for (int i = 0; i < n; i++)
        M[A[i]]++;

    for (int i = 0; i < n; i++)
        count += M[A[i] * A[i]];

    return count;
}
// Time O(n)
// Space O(n)

int main()
{
    int A[] = {2, 4, 5, 20, 16};
    int n = 5;

    cout << countSquaresByMap(A, n);
}