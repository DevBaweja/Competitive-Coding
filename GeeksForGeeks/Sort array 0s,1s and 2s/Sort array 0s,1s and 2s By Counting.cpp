#include <iostream>
using namespace std;

void sort012(int A[], int n)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
            count0++;
        if (A[i] == 1)
            count1++;
        if (A[i] == 2)
            count2++;
    }

    for (int i = 0; i < count0; i++)
        A[i] = 0;
    for (int i = count0; i < count0 + count1; i++)
        A[i] = 1;
    for (int i = count0 + count1; i < n; i++)
        A[i] = 2;
}
// Time- O(n)
// Traverse array twice
// Uniqueness of the elements are lost

int main()
{
    int A[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = 12;
    sort012(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}