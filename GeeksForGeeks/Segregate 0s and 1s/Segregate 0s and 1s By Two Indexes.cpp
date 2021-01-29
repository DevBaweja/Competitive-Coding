#include <iostream>
using namespace std;

void segregate01(int A[], int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        if (!A[left])
            left++;
        if (A[right])
            right--;
        if (left < right)
        {
            A[left] = 0;
            A[right] = 1;
            left++;
            right--;
        }
    }
}
// Time- O(n)
// Traverse array once
// Uniqueness of the elements are lost

void segregate01Type(int A[], int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        switch (A[left])
        {
        case 0:
            left++;
            break;
        case 1:
            swap(A[left], A[right--]);
            break;
        }
    }
}
// Time- O(n)
// Traverse array once
// Uniqueness of the elements are intact

int main()
{
    int A[] = {0, 1, 0, 1, 1, 1};
    int n = 6;
    segregate01Type(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}