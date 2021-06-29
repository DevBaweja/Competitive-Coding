#include <bits/stdc++.h>
using namespace std;

// jumps[k] means min # of jumps to reach k node from start node
int minJumps(int A[], int n)
{
    if (n == 0 || A[0] == 0)
        return INT_MAX;

    int max_reach = A[0];
    int step = A[0];
    int jumps = 1;

    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jumps;

        max_reach = max(max_reach, i + A[i]);
        step--;

        if (step == 0)
        {
            jumps++;
            if (i >= max_reach)
                return INT_MAX;
            step = max_reach - i;
        }
    }
    return INT_MAX;
}
// Time- O(n)
// Space- O(1)

int main()
{
    int A[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = 10;
    cout << minJumps(A, n);
    return 0;
}