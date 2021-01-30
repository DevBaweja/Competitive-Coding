#include <iostream>
using namespace std;

int maxSubArraySum(int A[], int n)
{
    int max_value = INT_MIN, cur_value = 0;

    for (int i = 0; i < n; i++)
    {
        cur_value += A[i];
        if (cur_value > max_value)
            max_value = cur_value;
        // Reseting
        if (cur_value < 0)
            cur_value = 0;
    }
    return max_value;
}

int kadane(int A[], int n)
{
    int max_value = A[0], cur_value = A[0];

    for (int i = 0; i < n; i++)
    {
        cur_value = max(A[i], cur_value + A[i]);
        max_value = max(max_value, cur_value);
    }

    return max_value;
}
// Time O(n)

int main()
{
    int A[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = 8;
    cout << kadane(A, n);
    return 0;
}
