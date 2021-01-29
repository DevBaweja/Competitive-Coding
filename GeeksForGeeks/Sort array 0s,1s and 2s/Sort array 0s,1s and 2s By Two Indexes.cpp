#include <iostream>
using namespace std;

// Dutch National Flag Algorithm OR 3-way Partitioning:
void sort012(int A[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        switch (A[mid])
        {
        case 0:
            swap(A[low++], A[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(A[mid], A[high--]);
        }
    }
}
// Time- O(n)
// Traverse array once
// Uniqueness of the elements are intact

int main()
{
    int A[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = 12;
    sort012(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}