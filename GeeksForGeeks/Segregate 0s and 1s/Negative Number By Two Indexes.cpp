#include <iostream>
using namespace std;

void rearrange(int A[], int n)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (A[left] < 0)
        {
            if (A[right] > 0)
                right--;
            left++;
        }
        else
        {
            if (A[right] < 0)
                swap(A[left++], A[right--]);
            else
                right--;
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