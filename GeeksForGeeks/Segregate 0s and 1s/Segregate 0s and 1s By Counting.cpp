#include <iostream>
using namespace std;

void segregate01(int A[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!A[i])
            count++;
    }

    for (int i = 0; i < count; i++)
        A[i] = 0;
    for (int i = count; i < n; i++)
        A[i] = 1;
}
// Time- O(n)
// Traverse array twice
// Uniqueness of the elements are lost

int main()
{
    int A[] = {0, 1, 0, 1, 1, 1};
    int n = 6;
    segregate01(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}