#include <iostream>
using namespace std;

// jumps[k] means min # of jumps to reach k node from start node
int minJumps(int A[], int n)
{
    int *jumps = new int[n];
    if (n == 0 || A[0] == 0)
        return INT_MAX;
    jumps[0] = 0;

    for (int i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (i <= j + A[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }

    return jumps[n - 1];
}

// jumps[k] means min # of jumps to reach last node from k node
int minJumps(int A[], int n)
{
    int *jumps = new int[n];

    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] == 0)
            jumps[i] = INT_MAX;
        else if (i + A[i] >= n - 1)
            jumps[i] = 1;
        else
        {
            int min = INT_MAX;
            for (int j = i + 1; j < n && j <= A[i] + i; j++)
            {
                if (min > jumps[j])
                    min = jumps[j];
            }

            if (min != INT_MAX)
                jumps[i] = min + 1;
            else
                jumps[i] = INT_MAX;
        }
    }
    return jumps[0];
}

// Time- O(n*n)
// Space- O(n)
// Dp Array

int main()
{
    int A[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = 10;
    cout << minJumps(A, n);
    return 0;
}