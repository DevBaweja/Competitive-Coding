#include <iostream>
using namespace std;

#define R 3
#define C 6

void spiral(int A[R][C], int i, int j, int m, int n)
{
    if (i >= m || j >= n)
        return;
    // i - Starting Row
    // m - Ending Row
    // j - Starting Column
    // n - Ending Column
    for (int p = j; p < n; p++)
        cout << A[i][p] << " ";

    for (int p = i + 1; p < m; p++)
        cout << A[p][n - 1] << " ";

    if ((m - 1) != i)
    {
        for (int p = n - 2; p >= j; p--)
            cout << A[m - 1][p] << " ";
    }
    if ((n - 1) != j)
    {
        for (int p = m - 2; p >= i; p--)
            cout << A[p][j] << " ";
    }
    spiral(A, i + 1, j + 1, m - 1, n - 1);
}
// Time- O(m*n)
// Space- O(1)

int main()
{
    int A[R][C] = {{1, 2, 3, 4, 5, 6},
                   {7, 8, 9, 10, 11, 12},
                   {13, 14, 15, 16, 17, 18}};

    spiral(A, 0, 0, R, C);
    return 0;
}