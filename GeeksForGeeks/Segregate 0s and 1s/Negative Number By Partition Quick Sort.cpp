#include <iostream>
using namespace std;

void rearrange(int A[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
        {
            swap(A[i], A[j]);
            j++;
        }
    }
}
// Time- O(n)

int main()
{
    int A[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = 9;
    rearrange(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}