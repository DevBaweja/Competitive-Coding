#include <iostream>
#include <vector>
using namespace std;

int maxJumps(int A[], int n, int k, vector<int> dp)
{

    if (dp[k] != -1)
        return dp[k];

    if (k == n - 1)
        return 1;

    if (A[k] == 0)
        return 0;

    for (int i = 1; i <= A[k]; i++)
        if (maxJumps(A, n, k + i, dp))
        {
            dp[k] = 1;
            return 1;
        }

    dp[k] = 0;
    return 0;
}

int canReach(int A[], int n)
{
    vector<int> dp(n, -1);
    return maxJumps(A, n, 0, dp);
}

int main()
{
    int A[] = {1, 2, 0, 3, 0, 0};
    int n = 6;
    cout << canReach(A, n);
    return 0;
}