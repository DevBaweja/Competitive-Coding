#include <iostream>
using namespace std;

#define R 3
#define C 6

void spiral(int m, int n, int A[R][C])
{
    // k - Starting Row
    // m - Ending Row
    // l - Starting Column
    // n - Ending Column
    int k = 0, l = 0;
    while (k < m && l < n)
    {
        for (int i = l; i < n; i++)
            cout << A[k][i] << " ";
        k++;
        for (int i = k; i < m; i++)
            cout << A[i][n - 1] << " ";
        n--;

        if (k < m)
        {
            for (int i = n - 1; i >= l; i--)
                cout << A[m - 1][i] << " ";
            m--;
        }
        if (l < n)
        {
            for (int i = m - 1; i >= k; i--)
                cout << A[i][l] << " ";
            l++;
        }
    }
}
// Time- O(m*n)
// Space- O(1)

int main()
{
    int A[R][C] = {{1, 2, 3, 4, 5, 6},
                   {7, 8, 9, 10, 11, 12},
                   {13, 14, 15, 16, 17, 18}};

    spiral(R, C, A);
    return 0;
}