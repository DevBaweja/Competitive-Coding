#include <iostream>
using namespace std;

int canReach(int A[], int N)
{
    int cur = N - 1;

    for (int i = N - 1; i >= 0; i--)
    {
        if (i + A[i] >= cur)
            cur = i;
    }
    if (cur)
        return 0;
    else
        return 1;
}
// Time - O(n)
// Space - O(1)

int main()
{
    int A[] = {1, 2, 0, 3, 0, 0};
    int n = 6;
    cout << canReach(A, n);
    return 0;
}